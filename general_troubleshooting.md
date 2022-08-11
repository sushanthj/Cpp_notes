---
layout: page
title: General Troubleshooting
permalink: General_troubleshooting
nav_order: 13
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc}
</details>

# C++ Helper Guide


## Basics to Begin

### Simple way
- To only compile files on the command line:

<i>g++ -o HelloWorld hello.cpp (where hello.cpp was the C++ code you wrote)

- To run a compiled file you can do:
  
  ```bash
  ./HelloWorld
  ```

### Alterantive

- You could also do:
  <i>g++ main.cpp -o main.out

- Then to run the code do: <i>./main.out


## Troubleshooting

1. When executing a program if the console window blinks and closes immediately

    ```cpp
    #include <iostream>
    #include <limits>

    // then at the end of your main function (before return statement)

    std::cin.clear(); // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    std::cin.get(); // get one more char from the user
    ```

2. Error: unresolved external symbol _main or _WinMain@16

This means your compiler can’t find your main() function. All programs must include a main() function.

# Useful Links

![lvalue_rvalue](https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/)