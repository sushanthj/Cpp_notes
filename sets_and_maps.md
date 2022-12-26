---
layout: page
title: Sets and Maps
permalink: Sets_and_maps
nav_order: 8
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc}
</details>


# Intro to Sets

In C++ the STL library has sets and unordered sets:
- ```#include <set>``` - is by default an ordered set
- ```#include <unordered_set>```

Internally, the elements of a set are organized into buckets and uses **hashing** to insert
elements into buckets. This makes it have constant time complexity!

## Simple set example
```cpp
#include <iostream>
#include <set>
#include <string>
#include <functional>

using namespace std;

int main()
{
  // to force keep in descending order
  //set<int, std::greater> Set;
  
  // Leaving it in ascending order
  set<int> Set = {1,2,3,4,1,2,3,4}

  for(const auto& e: Set)
  {
    cout << e << endl;
  }
  
  return 0;
}
```

Output:
```
1
2
3
4
```

Observations from above code:
- Sets do not allow for duplicate elements even if force fed
- The default arrangement of elements in an ordered set are ascending
- **Auto Iterators (const auto&)ddd**
  ![](/images/auto_iterator.png)


## Advanced Set examples (Set of Classes)

Here we perform operator overloading, observe the syntax

```cpp
#include <iostream>
#include <set>
#include <functional>
#include <string>

using namespace std;

class Person
{
  public:
    float age;
    string name;
  
  bool operator < (const Person& peep) const
  {
    return age < peep.age;
  }
};

int main()
{
  // defining set of classes
  set<Person> Set = { {30,"John"},{25,"Taylor"},{22,"Steve"}};
  for(const auto& e: Set)
  {
    cout << e.age << " " << e.name << endl;
  }

  return 0;
}
```

Output:
```
22 Steve
25 Taylor
30 John
```

## Mulitset

Here we will have a sorted set (with ability to handle duplicate objects)

```cpp
#include <iostream>
#include <set>
#include <functional>
#include <string>

int main()
{
  std::multiset<int, std::greater<>> multiset = {5,3,4,2,45,1}
  for(const auto& e: multiset)
  {
    cout << e << endl;
  }
  return 0;
}
```

Note: We can do ```std::greater<>``` or ```std::less<>``` for ascending or descending respectively

## Unordered Set

Uses hashing while the ordered set using Red-Black-Tree as backend datastructure. The syntax
for an unordered set is similar though as shown here:

```cpp
#include <iostream>
#include <set>
#include <functional>
#include <string>

int main()
{
  std::unordered_set<int, std::greater<>> uset = {5,3,4,2,45,1}
  for(const auto& e: multiset)
  {
    cout << e << endl;
  }
  return 0;
}
```


# Intro to Maps

- This is the closest to a python dictionary. 
- It works on Key-Value pairs.
- Each key must be unique
- Values can be repeated

## Ordered Map

The key-value pair is sorted according to the *key*

```cpp
#include <iostream>
#include <map>
#include <functional>
#include <string>

int main()
{
  std::map<std::string, int, std::greater<>> Map;

  // Two methods to initialize
  Map["John"] = 1002;
  Map.insert(std::make_pair("Bot", 1111));

  // Looping through map
  for(const auto &e: Map)
  {
    cout << e.first << " " << e.second << endl;
  }

  // print specific values
  cout << Map["John"] << endl;
  return 0;
}
```

- .first = Key
- .second = Value

## Multimap

Here the only difference is that we can have duplicate keys. An interesting way to develop
a range iterator is shown here:

```cpp
#include <iostream>
#include <map>
#include <functional>
#include <string>
using namespace std;

int main()
{
  std::multimap<std::string, int> Map;

  // WE CANNOT DO THIS ANYMORE BECAUSE OF AMBIGUITY
  // Map["John"] = 1002;
  // Map["John"] = 1003;
  Map.insert(std::make_pair("Bot", 1111));

  // Get all paris of a given key
  auto range = Map.equal_range('a');
  for(auto it = range.first; it != range.second; ++it)
  {
    cout << it->first << " " << it->second << endl;
  }
}
```

Note. The euqal_range function is bit tricky to understand. The line 
```auto range = Map.equal_range('a');``` returns two iterators

If we were to do this more explicitly it would look like:
```cpp
pair<map<std::string, int>::iterator,
         map<std::string, int>::iterator>
        it;

// define the iterator
it = Map.equal_range("Bot")

// print the bounds of the first and second pairs in iterator
cout << "The lower bound is "
         << it.first->first
         << ":" << it.first->second;
 
    cout << "\nThe upper bound is "
         << it.second->first
         << ":" << it.second->second;
 
    return 0;
```

As seen above, each iterator has it's own range
- First iterator upper-to-lower = lower bound
- Second iterator upper-to-lower = upper bound

All this drama of defining two iterators and their type is handled by using the ```auto``` 
type inference [Reference](https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/)

## Unordered Maps

Major difference here is that:
|                   Map                  | Unordered Map                        |
|:---------------------------------------|:-------------------------------------|
| Uses Red-Black-Tree backend datastruct | Uses buckets & hashing for backend DS|

```cpp
#include <iostream>
#include <map>
#include <functional>
#include <string>
using namespace std;

int main()
{
  std::unordered_map<std::string, int> umap = { {"bob",2}, {"john",3}};
  return 0;
}
```