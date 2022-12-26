---
layout: page
title: Vectors
permalink: vectors
nav_order: 7
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc}
</details>


# Intro

Similar to how we were using the STL library for I/O, string etc, we will now use another part
of this STL library for object oriented classes

**Vector class falls under such an object oriented class**

To instatiate a vector one must do:

```cpp
std::vector<int> vectorInts; 
```

- The vector has size 0 on instantiation
- We can *resize* it to change size of vector

```cpp
// constructing vectors
#include <iostream>
#include <vector>  //Need to include the vector library!


int main ()
{
  //creating a vector of integers
  std::vector<int> vectorInts;  
  std::cout<<"vectorInts has "<<vectorInts.size()<<" elements\n";
  
  //Changing the size of vectorInts to 6
  vectorInts.resize(6);
  std::cout<<"\n\nvectorInts now has "<<vectorInts.size()<<" elements\n";
 
  return 0;
}
```

Output:
```
vectorInts has 0 elements 
vectorInts now has 6 elements

```

_________________________________________________________________________________________

# Why we use vectors

1. They are more versatile than arrays (they can be changed during runtime)
2. New elements can be added or removed from the vector
3. **Basically a vector in C++ = list in Python**
 
## Vector Iterators

Like any list, we need an iterator to keep track of where we are in a vector. However, this
is more explicit than just looping over a list like ```for i in list: print(i)```

```cpp
//creating an iterator for the vector
// notice how iterator seems to be a member function of the superclass vector
std::vector<int>::iterator it;

for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
    std::cout<<*it<<" ";
```
- Notice how we deference the iterator to print the value of the vector at that position
  ```cpp
  std::cout<<*it<<" ";
  ```
- This means that iterator is a pointer by default
  Remember:
  - pointerToA = address value
  - *pointerToA = value (deferenced)

## Simple vector operations example

main.cpp
```cpp
//TODO: Add the necessary libraries
#include "main.hpp"
#include<vector>

int main ()
{
  //TODO: create a vector of floats
  std::vector<float> vFloat;
  
  std::cout<<"vFloat has "<<vFloat.size()<<" elements\n";
  
  std::cout<<"\n\nAdding 10 elements to the vector\n";
  vFloat.resize(10);
  
  //TODO: assign the value 8.8 to 10 elements of the vector
  std::fill(vFloat.begin(), vFloat.end(), 8.8);
  
  //Easier way to do it
  std::vector<float> vFloat2(10, 8.8);
   
  std::cout<<"vFloat has "<<vFloat.size()<<" elements\n"; 


  //TODO: Complete the Print function in main.hpp 
  // Call the function here to print out each element of vFloat
  std::cout<<"first element of vFloat is "<<vFloat[0];
  std::cout<<"first element of vFloat2 is "<<vFloat2[0];

  std::cout<<"Adding 23 to the vector\n";
  vFloat.assign(1,23);
  for (it = vFloat.begin(); it != vFloat.end(); ++it)
    std::cout<<*it<<" ";
  
  std::cout<<"\n\nAdding four elements to the vector\n";
  //assigning the value 3 to 4 elements of the vector
  vFloat.assign(4,3);
  
  printVector(vFloat);

  return 0;
}
```

main.hpp
```cpp
#include <iostream>
#include <vector>

using namespace std;

// function declaration
void printVector(vector<float> vIn);

// function definition
 void printVector(vector<float> vIn)
 {//printing the contents of vIns
    //TODO: Complete the function 
    
    std::vector<float>::iterator it;
    for(it = vIn.begin(); it != vIn.end(); ++it)
    {
        std::cout<<*it<<" ";
    }
 }
```

### Syntax for assigning:

vector.assign(1,10) = assign value = 10 to index 1


Note. Just like in python, here too the array indices start from 0

## Adding elements

vector.assign just writes over the elements in the vector. However, if we just want to append
then we can do so by vector.push_back() which adds elements to back of list (end of list)

```cpp
#include <iostream>
#include <vector>


int main ()
{
  //creating a vector of integers (currently has zero elements)
  std::vector<int> vectorInts;  
  //creating an iterator for the vector
  std::vector<int>::iterator it;
  
  std::cout<<"vectorInts has "<<vectorInts.size()<<" elements\n";
  
  std::cout<<"Adding 23 to the vector\n";
  vectorInts.assign(1,23); // currently has added only one element to array (size = 1)
  

  std::cout<<"\n\nAdding four elements to the vector\n";
  //assigning the value 3 to 4 elements of the vector
  vectorInts.push_back(24);
  vectorInts.push_back(25);
  vectorInts.push_back(26);
  vectorInts.push_back(27);
  
  //printing the contents of vectorInts
  std::cout<<"VectorInts has these elements:\n";
  for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
    std::cout<<*it<<" ";
 
  return 0;
}
```

Output:
```
vectorInts has 0 elements 
Adding 23 to the vector 
Adding four elements to the vector 
VectorInts has these elements: 23 24 25 26 27
```

## Insert elements

```cpp
#include <iostream>
#include <vector>


int main ()
{
  //creating a vector of integers
  std::vector<int> vectorInts;  
  //creating an iterator for the vector
  std::vector<int>::iterator it;

  vectorInts.push_back(0);
  vectorInts.push_back(1);
  vectorInts.push_back(2);
  vectorInts.push_back(3);
  vectorInts.push_back(4);
  vectorInts.push_back(5);
  vectorInts.push_back(6);
  vectorInts.push_back(7);
  
  //printing the contents of vectorInts
  std::cout<<"VectorInts has these elements:\n";
  for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
    std::cout<<*it<<" ";
 
  //insert an element after the first element
  it  = vectorInts.begin() + 1;
  vectorInts.insert(it, -1);
  std::cout<<"\n\nAfter the insert\n";
for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
    std::cout<<*it<<" ";

  return 0;
}
```

Output:
```cpp
VectorInts has these elements: 0 1 2 3 4 5 6 7 
After the insert 0 -1 1 2 3 4 5 6 7
```

Note the steps above:
1. Create an iterator object using: ```std::vector<int>::iterator it```
2. Set the iterator to the index you want: ```it  = vectorInts.begin() + 1```
3. Do the insertion: ```vectorInts.insert(it, -1)```

### Emplace vs Insert

- Insert adds the new element to the next position of the iterator
- Whereas empace adds it to that position of the iterator itself

```cpp
//insert an element after the first element
  it  = vectorInts.begin() + 1;
  vectorInts.emplace(it, -1);
```

Check out this for more reference: [REF](https://stackoverflow.com/questions/14788261/c-stdvector-emplace-vs-insert)

## Removing from an array

### vector.clear()

Removes all elements from array
```cpp
 //clear the vector
  vectorInts.clear();
```

### vector.erase()

- Remove a single element from a vector
  ```cpp
  //erase the 5th element in the vector
  vectorInts.erase(vectorInts.begin()+4);
  ```

- Remove a range of values:
  ```cpp
  //erase a range of elements in the vector
  vectorInts.erase(vectorInts.begin()+1, vectorInts.begin()+3);
  ```

### vector.pop_back():
  ```cpp
  //pop the last element off the vector
  vectorInts.pop_back();
  ```

  Note. .pop_back() has no return value!
  
  The below code will not compile
  ```cpp
  int a; 
  a = vectorInts.pop_back(); //this line does not compile
  ```
