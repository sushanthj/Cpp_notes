---
layout: page
title: Heaps
permalink: Heaps
nav_order: 9
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc}
</details>

**This is a starter to learn about min heaps and priority queues**. To learn more
[Ref Video](https://www.youtube.com/watch?v=hOjcdrqMoQ8&ab_channel=NeetCode)

# Non-optimized approach to search (vectors)

- Sort the input array so that we can search for any number in log(n) time (Binary Search)
- However, adding any new element into the sorted array with O(n) time
- Therefore it doesn't seem too optimal. Could there be something better?

# Optimal approach (Heaps)

Here we'll specifically use a Min heap. These have **kinda sorted properties**.

**The advantage of heaps over vectors/arrays is**
- We can add and pop elements in log(n) time vs the O(n) time with vectors
- **We can get min value of min_heap in O(1)** which is definitely better than an unsorted array
- Also, we only need a min heap because we need only the kth largest values in heap
  and we don't care about other elements. Also we'll never be removing elements, just
  adding them again and again.
- **Therefore all we need is a min-heap of size K**
- We'll essentially keeping popping the min element of the heap until heap is of size K

## Summary
- Heap is just like a vector (in that it's unsorted), but it can give min value in log(n) time
- Usually stacks are preferred over heaps since they are faster and have easier memory access
- Heaps are implemeneted from full binary trees

### Lessons Learnt

1. How is a heap better than a vector
2. How to use a heap in C++ [Ref](https://www.geeksforgeeks.org/heap-using-stl-c/)

# Working with Heaps in C++

1. Creation of heap from a list type container (officially called range container):
   ```cpp
   // Initializing a vector
   vector<int> v1 = {20, 30, 40, 25, 15};
       
   // Converting vector into a heap
   // using make_heap()
   make_heap(v1.begin(), v1.end());
   ```

2. Getting max element of a max heap \
   The max element of a heap = Front of heap i.e. ```v1.front()```

3. To define a min heap is a bit tricky in C++. We need to use priority queue (part of ```<queue>``` library) which uses min_heap in background

4. **Efficiently Init a priority_queue from a vector (but works only for max heap :/)**
   ```cpp
   int main()
   {
        int arr[] = { 15, 25, 6, 54, 45, 26, 12 };
        int N = sizeof(arr) / sizeof(arr[0]);

        // Initialize priority_queue
        priority_queue<int> pq(arr, arr + N);

        // print individual elements
        while (!pq.empty()) 
        {
            // Print the element
            cout << pq.top() << " ";
            pq.pop();
        }
   }
   ```

5. doing priority_queue.size() takes only O(1) time complexity

6. Since we can only add to heap (can't add to front or back), just like a queue
   therefore we can only do ```pq.push(5)``` and it will automatically know where to add it

## Example with heaps in C++

```cpp
#include <queue>
class KthLargest {
private:
    int k;
public:
    priority_queue < int, vector<int>, greater<int> > min_heap;
    
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        // add all elements in vector to heap
        for(int i = 0; i < nums.size(); i++) min_heap.push(nums[i]);

        // now start popping the min elements of the heap
        // i.e. start by popping the top of heap = min element
        // we pop from the min side since we want kth largest
        while(min_heap.size() > k) min_heap.pop();
    }
    
    int add(int val)
    {
        // add new val to heap whatever the case
        min_heap.push(val);
        
        // after adding new val we need to resize the heap
        // so that we still have kth largest elements only
        // therefore, to make space we again pop the min element
        if(min_heap.size() > this->k) min_heap.pop();

        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

**Note. Using this variable makes life easy here (think of this->k as self.k in python)**
- We've added a private variable ```int k``` (which is usually not there in leetcode). 
- The reason is that we need the k value to be accessed by a member function ```int add```
- Therefore, it needs to be declared as a local class variable (like self in python)
- To make it a local variable, we need to put it under the private declaration.


## Another example of Heaps (Max Heap derived from Vectors here)

This is a starter to learn about max_heaps (without using priority queues)

![](/images/last_stone.png)

### My C++ Solution

```cpp
#include <queue>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // init placeholder for max and 2nd max value of heap
        int max1 = 0;
        int max2 = 0;
        
        // init a heap from the given vector
        make_heap(stones.begin(), stones.end());

        // alternative way of making heap is to use priority queue

        // priority_queue <int, vector<int>> max_heap;
        // for(int i=0; i < stones.size(), i++) max_heap.push(stones[i])

        // iterate until we have one stone left
        while(stones.size() > 1)
        {
            // extract first largest ('y' in problem statement)
            max1 = stones.front();
            cout << max1;

            // remove from heap first
            pop_heap(stones.begin(), stones.end());
            // remove from vector
            stones.pop_back();

            // extract second largest ('x' in problem statement)
            max2 = stones.front();
            cout << max2;

            // remove from heap first
            pop_heap(stones.begin(), stones.end());
            // remove from vector
            stones.pop_back();

            // if equal don't do anything as both elements have been popped
            if ((max1 == max2) && stones.size() != 0) continue;

            else if ((max1 == max2) && stones.size() == 0)
            {
                stones.push_back(0);
            }

            // if not equal then reduce y and add it back
            else
            {
                max1 = max1-max2;
                
                // add to vector first
                stones.push_back(max1);
                // reorder heap after new addition
                push_heap(stones.begin(), stones.end());
            }
        }
        return stones.front();
    }
};
```