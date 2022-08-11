---
layout: page
title: Basics
permalink: Basics
nav_order: 3
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc}
</details>


## Basics to Begin

- To only compile files on the command line:

<i>g++ -o HelloWorld hello.cpp (where hello.cpp was the C++ code you wrote)


## Objects and Variables

In C++, direct memory access is not allowed. Instead, we access memory indirectly through an object. An object is a region of storage (usually memory) that has a value and other associated properties.

The key point here is that rather than say go get the value stored in mailbox number 7532, we can say, go get the value stored by this object. This means we can focus on using objects to store and retrieve values, and not have to worry about where in memory they’re actually being placed.

### Best practice for variables

1. Declaration  
    ```cpp
    int a, double b; // wrong (compiler error)

    int a; double b; // correct (but not recommended)

    // correct and recommended (easier to read)
    int a;
    double b;
    ```

    Although the language allows you to do so, avoid defining multiple variables in a single statement (even if they are the same type). Instead, define each variable in a separate statement (and then use a single-line comment to document what it is used for).

2. Initializations

    C++ offers a form of initialization called brace initialization. **Favor initialization using braces whenever possible.**

    ```cpp
    int width = 5; // copy initialization of value 5 into variable width
    int width { 5 }; // direct brace initialization of value 5 into variable width (preferred)

    // you could also not initialize in cases where value is going to change immediately
    int x {}; // value initialization
    std::cin >> x; // we're immediately replacing that value

    int a, b = 5; // wrong (a is not initialized!)
    int a = 5, b = 5; // corr
    ```

# Intro to iostream

![General format of headers](/images/cpp_headers.png)
Note how the iostream is inside quotes here. That says that iostream is present in the present working directory and the compiler has to look there

1. Concatenation in std::cout

    To print more than one thing on the same line, the insertion operator (<<) can be used multiple times in a single statement to concatenate
    ```cpp
    #include <iostream> // for std::cout

    int main()
    {
        std::cout << "Hello" << " world!";
        return 0;
    }
    ```

2. \n equivalent here is endl

    ```cpp
    #include <iostream> // for std::cout and std::endl

    int main()
    {
        std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line of the console
        std::cout << "My name is Alex." << std::endl;

        return 0;
    }
    ```

    Or you could also used \n itself :P (**this is also more preferred**)
    ```cpp
    #include <iostream> // for std::cout

    int main()
    {
        int x{ 5 };
        std::cout << "x is equal to: " << x << '\n'; // Using '\n' standalone
        std::cout << "And that's all, folks!\n"; // Using '\n' embedded into a double-quoted piece of text (note: no single quotes when used this way)
        return 0;
    }
    ```

3. Taking user input using std::cin

    Here note the direction of the *<<*
    ```cpp
    int main()
    {
        std::cout << "Enter a number: "; // ask user for a number

        int x{ }; // define variable x to hold user input (and zero-initialize it)
        std::cin >> x; // get number from keyboard and store it in variable x

        std::cout << "You entered " << x << '\n';
        return 0;
    }
    ```

    Just like it is possible to output more than one bit of text in a single line, it is also possible to input more than one value on a single line

    ```cpp
    #include <iostream>  // for std::cout and std::cin

    int main()
    {
        std::cout << "Enter two numbers separated by a space: ";

        int x{ }; 
        int y{ }; 
        std::cin >> x >> y; // get two numbers and store in variable x and y respectively

        std::cout << "You entered " << x << " and " << y << '\n';

        return 0;
    }
    ```

4. Not having to define std namespace in each line
   
   We can define std namespace before function declaration:
   ```cpp
    using namespace std;
    int main():
    {
        cout<<"Hello World"
        reutrn 0;
    }

5. Difference between \n and endl in CPP

    Both can be used in code as shown below:
    ```cpp
    cout << "Hello World" << endl
    cout << "Hey World" << "\n"
    ```

    ![Difference Between endl and \n](/images/endl_%5Cn.png)

# Memory Allocations and Sizes

To check the memory consumed by different variable types we can do the following:

```cpp
sizeof(int)
sizeof(double)
```
The above code will return a string

## Uninitialized Variables

Unlike some programming languages, C/C++ does not initialize most variables to a given value (such as zero) automatically. Thus when a variable is assigned a memory location by the compiler, the default value of that variable is whatever (garbage) value happens to already be in that memory location! 

Therefore if you don't give it any value it becomes uninitialized

## Variable naming conventions

- Most often, function names are also started with a lowercase letter, as are all of the functions in the standard C++ libraries

- Identifier names that start with a capital letter are typically used for user-defined types (such as structs, classes, and enumerations)

- If the variable or function name is multi-word, there are two common conventions: words separated by underscores, called snake_case, or intercapped (sometimes called camelCase, since the capital letters stick up like the humps on a camel)

- You should avoid naming your identifiers starting with an underscore, as these names are typically reserved for OS, library, and/or compiler use


## Formatting Best Practices

1. Each statement within curly braces should start one tab in from the opening brace as seen below:

    ```cpp
    int main()
    {
        std::cout << "Hello world!\n"; // tabbed in one tab (4 spaces)
        std::cout << "Nice to meet you.\n"; // tabbed in one tab (4 spaces)
    }
    ```

2. Cap line length as done by common linters (**80 is what is suggested here**)

    multiline statements look like this:
    ```cpp
    int main()
    {
       std::cout << "This is a really, really, really, really, really, really, really, "
            "really long line\n"; // one extra indentation for continuation line

       std::cout << "This is another really, really, really, really, really, really, really, "
                    "really long line\n"; // text aligned with the previous line for continuation line

       std::cout << "This one is short\n";
    }
    ```


## Commenting

1. Single-line comments

    ```cpp
    std::cout << "Hello world!"; // Everything from here to the end of the line is ignored
    ```

2. Multi-line comments

    This can be achieved in two ways:
    ```cpp
    /* This is a multi-line comment.
   This line will be ignored.
   So will this one. */
   ```

   Or
   ```cpp
   /* This is a multi-line comment.
    * the matching asterisks to the left
    * can make this easier to read
    */
   ```

# Arithmetic Operations

## cmath library

This allows for uses like exponentials
```cpp
#include <cmath>

std::pow(base, exponent);
M_PI = 3.14 //it has more decimal places not shown here
// M_PI is a standard variable of the cmath library
```

## Weird Implicit conversions

Check out the following code:
```cpp
#include <iostream>
int main(void)
{
    int numerator = 4;
    int denominator = 5;

    float answer = numerator / denominator;
    std::cout<<"answer = "<<answer;
    return 0;
}
```

The output for the above scrit is `0`
Which is messed up because answer datatype is float xD

The corrections to the above code to get `answer = 0.8` is:

```cpp
#include <iostream>
int main(void)
{
    float numerator = 4;
    float denominator = 5;

    float answer = numerator / denominator;
    std::cout<<"answer = "<<answer;
    return 0;
}
```

## Prefix and Postfix operators

```cpp
#include <iostream>
 
int main()
{
    int n1 = 1;
    int n2 = ++n1;
    int n3 = ++ ++n1;
    int n4 = n1++;
//  int n5 = n1++ ++;   // error
//  int n6 = n1 + ++n1; // undefined behavior
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n'
              << "n3 = " << n3 << '\n'
              << "n4 = " << n4 << '\n';
}
```

The output for the above is:
```bash
n1 = 5
n2 = 2
n3 = 4
n4 = 4
```

