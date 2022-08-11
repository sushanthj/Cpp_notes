---
layout: page
title: Control Flow
permalink: Control_Flow
nav_order: 4
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc}
</details>


# Before you Begin

To create an array we need to use [] as shown in the example below:

```cpp
#include<iostream>
#include<string>

int main()
{
    //instead of printing 0 and 1, create an array where 
    //0 = False, 1 = True
    std::string TorF[] = {"False", "True"};
    
    int a = 100;
    int b = 33;
    int c = 33;
    
    //Print out the string values of each relational operation
    std::cout<<"a < b is "<<TorF[a<b];
  
    return 0;
}
```

### Logical operators in C++ are:
- &&
- `||`
- !

# If and Switch

## If statements

```cpp
//Use if-else statements to control program flow
   if(skin == 'f')
    {
        std::cout<<"Get a dog"<<"\n";
    }
    else if(skin == 't')
    {
        std::cout<<"Get a bird"<<"\n";
    }
    else if(skin == 's')
    {
        std::cout<<"Would you like an animal that lives in water(w), land(l), or both(b)?";
        std::cin>>location;
        std::cout<<location<<"\n";

        //Use if-else statements to control program flow
        //note that the curly braces are not necessary if there is only
        //one line of code.

        if(location == 'w')
            std::cout<<"Get a fish"<<"\n"; 
    }
```

## Switch Case

Basic Syntax:
```cpp
switch(menuItem)
    {
        case(1): std::cout<<"Skiing?! Sounds dangerous!\n";
                 break;
        case(2): std::cout<<"Sledding?! Sounds like work!\n";
                 break; 
        case(3): std::cout<<"Sitting by the fire?! Sounds warm!\n";
                 break;
        case(4): std::cout<<"Hot chocolate?! Yum!\n";
                 break;
        default: std::cout<<"Enter a valid menu item";
    }
```
If the break statement is not specified (which still works), the next cases after the selection will cascade and be executed

# Loops

1. Simple init, condition, increment **for loops**:
   
   ```cpp
    int main()
    {
        for(int i=0; i< 10;i++)
        {
            std::cout<<"i = "<<i<<"\n";
        }
        return 0;
    }
    ```

2. **While loops**
    ```cpp
    while(entry <=5)
    {
        std::cout<<"incrementing entry = "<<entry<<"\n";
        entry++;
    }
    ```

3. Do While Loops (these execute before checking condition)
    ```cpp
    do
    {
        std::cout<<"Count = "<<count<<"\n";
        count++;
    }while(count < 5);
    ```

