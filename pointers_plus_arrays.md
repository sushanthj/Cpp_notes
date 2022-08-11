---
layout: page
title: Pointers & Arrays
permalink: Pointers_and_Arrays
nav_order: 5
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

Bjourne says that pointers should be used judiciously since they may make computation slowly due to dereferncing and other activities of pointers. 

Also, they should be abstracted at higher levels so that it becomes easy to read code. Basically pointers should be hidden away well at higher levels.

![pointers](/images/pointers.png)

# Deferencing of Pointers

- This is the act of accessing the value stored at the location which the pointer is pointing to.
- This act is represented by the `*` operator

![deferencing_pointers](/images/deferencing_pointers.png)

**In the above image we can see that:**
- **pointerToA = address value**
- ***pointerToA = value (deferenced)**

Another example to illustrate:
```cpp
/*For this program print for each variable
**print the value of the variable, 
**then print the address where it is stored. 
*/
#include<iostream>
#include<string>

int main()
{
    int givenInt;
    std::string givenString;
    char givenChar;
    
    //printing the values of each of these variables
    std::cout<<givenInt<<"\n";
    std::cout<<"string is"<<givenString<<"\n";
    std::cout<<givenChar<<"\n";
    
    //printing the address of these variables
    std::cout<<&givenInt<<"\n";
    std::cout<<&givenString<<"\n";
    std::cout<<&givenChar<<"\n";
    return 0;
}
```

But the alternative cleaner way to do it is:
```cpp

//*Sample program for Pointers*/

#include<iostream>
#include<string>

int main()
{
    std::string name;
    int givenInt;
    float givenFloat;
    double givenDouble;
    std::string givenString;
    char givenChar;
    int *pointerGivenInt;
    int **pointerPointerGivenInt;

    pointerGivenInt = &givenInt;
    pointerPointerGivenInt = &pointerGivenInt;

   //Get the values of each variable
    std::cout<<"integer = \n";
    std::cin>>givenInt;
    std::cout<<"float = \n";
    std::cin>>givenFloat;
    std::cout<<"double = \n";
    std::cin>>givenDouble;
    //We need to use cin.ignore so cin will ignore 
   //the characters in the buffer leftover
   //from the givenDouble
    std::cin.ignore();
    std::cout<<"character = \n";
    std::cin>>givenChar;

    std::cout<<"string = \n";
    std::cin.ignore();
    std::getline (std::cin,givenString);


    //The value stored in the data
    std::cout<<"integer = "<<givenInt<<"\n";
    std::cout<<"float = "<<givenFloat<<"\n";
    std::cout<<"double = "<<givenDouble<<"\n";
    std::cout<<"string = "<<givenString<<"\n";
    std::cout<<"character = "<<(char)givenChar<<"\n\n";

    //The address of the data - use pointers
    std::cout<<"address integer = "<<&givenInt<<"\n";
    std::cout<<"address float = "<<&givenFloat<<"\n";
    std::cout<<"address double = "<<&givenDouble<<"\n";
    std::cout<<"address string = "<<&givenString<<"\n";
    std::cout<< "address character = " << (void *) &givenChar<<"\n\n";

   //Use indirection to the get the value stored at the address
   //this is basically deferencing a pointer (as we are using the * symbol)
    std::cout<< "pointer of givenInt = " << *pointerGivenInt<<"\n";
    std::cout<< "pointer of pointer of givenInt = " << **pointerPointerGivenInt<< "\n";

    return 0;
}
```

**Note how the char variable address and pointers are treated**

The output will look like the follwing:
```
integer = 
float = 
double = 
character = 
string = 
integer = 32
float = 64.212
double = 4.76545
string = Hey look at me! I know pointers!"
character = *

address integer = 0x7ffd812a9258
address float = 0x7ffd812a925c
address double = 0x7ffd812a9278
address string = 0x7ffd812a9270
address character = 0x7ffd812a9257

pointer of givenInt = 32
pointer of pointer of givenInt = 32
```

# Arrays

## Case Study: Counting Problem
```cpp
#include <iostream>

int main()
{
    int userInput = 0;
    int maxNumber = 0;
    int minNumber = 100;
    int sumTotal = 0;
    float average = 0; 

    //get the numbers from the user
    for(int i = 0; i < 15; i++)
    {
        std::cout << "Enter a number: ";
        std::cin>>userInput;
        std::cout << userInput << "\n";
        if(userInput > maxNumber)
        {
            maxNumber = userInput;
        }
        if(userInput < minNumber)
        {
            minNumber = userInput;
        }
        sumTotal = sumTotal + userInput;
    }
    std::cout << "Maximum number = " << maxNumber << "\n";
    std::cout << "Minimum number = " << minNumber << "\n";
    average = sumTotal / 15.0;
    std::cout << "Average = " << average << "\n";
    return 0;
}
```

Another similar problem. But this uses **scanf**

**Note how we use a pointer when using scanf**
```cpp
#include <iostream>
#include <stdio.h>

int main()
{
    int userInput[40];

    //Enter the numbers into an array called userInput
    for(int i = 0; i < 40; i++)
    {
        scanf("%d", &userInput[i]);
    }
    //print the array
    std::cout<<"\nThe array\n";
    for(int i = 0; i < 40; i++)
    {
        std::cout << userInput[i] <<" ";
    }
    //print the array in reverse order
    std::cout<<"\n\nThe array in reverse order\n";
    for(int i = 39; i >= 0; i--)
    {
        std::cout << userInput[i] <<" ";
    }
}
```

## Case Study: Search Problem

```cpp
 #include <iostream>
 #include <stdio.h>

 int main()
 {
     int searchKey = 0;
     int searchArray[10] = {324,4567,6789,5421345,7,65,8965,12,342,485};
     int location = 0;

     while(1)
     {
         std::cout<<"Enter an integer ('-1' to quit): ";
         scanf("%d", &searchKey);
         std::cout<< searchKey<<"\n";
         if(searchKey == -1)
         {
             break;
         }
         for(int i = 0; i < 10; i++)
         {
             if(searchKey == searchArray[i])
             {
                 location = i;
                 break;
             }
             location = -1;
         }
         if(location != -1)
         {
             std::cout<<searchKey<<" is at location "<<location<<" in the array.\n";
         }
         else
         {
             std::cout<<searchKey<<" is not in the array.\n";
         }
    }
     return 0;
 }
```

# Multidimensional Arrays

To create a 2x3 array you just need to do:
`int array2d[2][3];`

You could also initialize them with:
`int array2D[2][3] = {0,1,2,3,4,5};`

But this will initialize it in the row-major order, i.e.:
- [0][0]
- [0][1]
- [0][2]
- [1][0]
- [1][1]
- [1][2]

