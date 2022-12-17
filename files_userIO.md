---
layout: page
title: Files, User IO and Variables
permalink: File_ops
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

## Some Distinct Variable Types

1. Constant variables

    These are immutable types are defined as shown below:
    ```cpp
    const int weightGoal = 100;
    ```

2. Enumerated constants
    
    We are given the option of creating a variable which can hold only a finite number of values
    
    **the enum class acts as a constructor object with a specific set of values only**

    ```cpp
    int main()
    {
        //define MONTHS as having 12 possible values
        enum MONTHS {Jan, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
        
        //define bestMonth as a variable type MONTHS
        MONTHS bestMonth;
        
        //assign bestMonth one of the values of MONTHS
        bestMonth = Jan;
        
        //now we can check the value of bestMonths just 
        //like any other variable
        if(bestMonth == Jan)
        {
            cout<<"I'm not so sure January is the best month\n";
        }
        return 0;
    }
    ```

## Output formatting

### Using IOMANIP

It's a standard library which helps format output text

```cpp
#include <iomanip>

std::cout<<"Ints"<<std::setw(15)<<"Floats"<<std::setw(15)<<"Doubles"<< "\n";
```

The std::setw(15) sets the width to 15

# File Operations

## Using the fstream class

Here we will be writing and then reading the contents of a file

The first step is to include the **<fstream>** library

Basic steps:

 - Include the <fstream> library 
 - Create a stream (input, output, both)
      - ofstream myfile; (for writing to a file)
      - ifstream myfile; (for reading a file)
      - fstream myfile; (for reading and writing a file)
 - Open the file  myfile.open(“filename”);
 - Write or read the file
 - Close the file myfile.close();

During some file handling ops you may see **ios::app** mentioned during file opening \
This ios is the base class for fstream, ofstream and ifstream (you don't need to worry about it)

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line;
    
    fstream fio;
    //create an output stream to write to the file
    //append the new lines to the end of the file
    fio.open("input.txt", ios::out | ios::in);
    if (fio)
    {
        fio.seekg(0, ios::end);
        fio << "adding a line \n" << "\n"; //the second \n does nothing
                                            //as fio takes only 1 string
        fio << "adding another line";
        fio.seekg(0, ios::beg);
    }
    else cout << "Unable to open file for writing";
  
    //create an input stream to write to the file
    fstream("input.txt", ios::in | ios::out);
    if (fio)
    {
        while ( getline (fio,line) ) //each line is getting read(var line is a string)
        {
            cout << line << "\n"; //this appends a newline to cout
        }
    }
    
    else cout << "Unable to open file for reading";
    
    fio.close();
    
    return 0;
}
```

## Header Files

- These have a **.hpp** extension and **can be custom created**

- Generally the header files should contian info on **how** to do a task while the main file
  should contain info on **what** to do the task

### Sample header file and it's use

The *how to do* part of the code is in a header file called trial_header.hpp like:
  ```cpp
  #include <iostream>
  #include <string>

  using namespace std;
  ```

Now we will use that info to figure out *what to do* in the main program:
```cpp
#include "trial_header.hpp"

int main()
{
  cout <<"Hello world I am using header files!";
  return 0;
}
```


# Strings

## String Stream Library

Steps for using this library:
- Include the Stringstream library \
  ` #include <sstream> `

- Use getline and cin as shown above to get string from user \
  ` std::getline(std::cin, stringVariable) `

- Convert the string variable to a float variable \
  ` std::stringstream(stringVariable) >> numericVariable `

## Differnt ways to taking User Input

### Case Study: Taking User input and converting the input string to float

```cpp
#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;

int main()
{
    string length;
    string width;
    float length_numeric;
    float width_numeric;
    double area;
    
    cout << "Enter the length of a room \n";
    getline(cin, length);
    stringstream(length) >> length_numeric;
    
    cout << "Enter the width of the room \n";
    getline(cin, width);
    stringstream(width) >> width_numeric;
    area = length_numeric*width_numeric;
    cout << "Area of the room is" << area << endl;
}
```

### Case Study: Directly taking int input

```cpp
int main()
{
  int target = 55;
  int guess = -1;

  while(guess != target)
  {
    std::cout<<"Guess a number between 0 and 100: ";
    std::cin>>guess;
    std::cout<<guess<<"\n";
  }
}
```

### Summarizing User IO options
```cpp
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
```

## Using scanf
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
}
```