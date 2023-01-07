---
layout: page
title: Stacks
permalink: Stacks
nav_order: 10
---

## Refresher
- Stacks are FIFO methods
- queues are FILO methods
- deques allow for insertion in front or end and popping in front or end

# Toy Problem

```cpp
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> stack;
    stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(22);
    stack.push(24);
    stack.push(25);
    int num=0;
      stack.push(num);
    stack.pop();
    stack.pop();
      stack.pop();
   
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
}
```

Output:
```
22 21
```