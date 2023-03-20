## Trie Implementation in C++
https://leetcode.com/problems/longest-common-prefix/submissions/918587275/

## Binary Search functions in C++ STL (binary_search, lower_bound and upper_bound)

https://www.geeksforgeeks.org/binary-search-functions-in-c-stl-binary_search-lower_bound-and-upper_bound/

## C++ equivalent of Python String Slice?

```cpp
std::string text = "Apple Pear Orange";
std::cout << text.substr(6, std::string::npos) << std::endl; // "Pear Orange"
```

## How to initialize a vector of pairs in CPP

```cpp

vector<pair<int, int>> myVec (N, std::make_pair(-1, -1));

std::vector<std::pair<int, int> > vec1 = { {1, 0}, {2,0}, {3,1} };

std::vector<std::pair<int, int> > vec2 = {std::make_pair(1, 0),
                                           std::make_pair(2, 0),
                                           std::make_pair(3, 0)};
      
```


                                           


## Some important vector operations 

```cpp
it = std::find (vec.begin(), vec.end(), ser);
if (it != vec.end())
{
    std::cout << "Element " << ser <<" found at position : " ;
    std::cout << it - vec.begin() << " (counting from zero) \n" ;
}
```

```cpp
 reverse(result.begin(),result.end());
```


## Some rules while using priority_queue and queue 
👉 **Don't use** & while referring to the top element. 

For example: 

```cpp
 auto& obj1 = pq.top();            
 pq.pop();            
 auto& obj2 = pq.top();            
 pq.pop();
```

## packing and unpacking multiple values in C++

#### tuple 
Common C++ data structures like vectors, arrays, priority queues, etc., can contain elements of a single data type. So when we need a data structure that can hold a fixed number of elements of different data types together, tuples are useful, as they may contain any data type, both primitive and abstract data types like string.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    // Declare and initialise tuple.
    tuple <int, double, char> tp(4, 0.6, 'z');
    // Print elements.
    cout << get<0>(tp) << "  " << get<1>(tp) << "  " << get<2>(tp);
    return 0;
}
```



#### tie

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {

    tuple <string, int, bool> tp("sample", 56, false);

    string var1;
    int var2;
    bool var3;

    // tie() is used below for unpacking tuple values.
    tie(var1, var2, var3) = tp;

    cout << "The unpacked values of the tuple elements are:  ";
    cout << var1 << ",  " << var2 << ",  " << var3;

    return 0;
}
```
👉 We may want to prevent some values from getting unpacked. To do this, we use "ignore" instead of the particular variable as an argument to tie().

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {

    tuple <string, int, bool> tp("sample", 56, false);

    string var1;
    bool var2;

    // tie() is used below for unpacking tuple values, with ignore being used to prevent unpacking of the 2nd element.
    tie(var1, ignore, var2) = tp;

    cout << "The unpacked values of the tuple elements are:  ";
    cout << var1 << ",  " << var2;

    return 0;
}
```


## How to initialize a 2D matrix with -1

```cpp
int row= 3;
    
vector<vector<int>> dp(row, vector<int>(row, -1));
```
    

## max and min numbers in C++

```cpp
#include <iostream>
#include <limits>
 
int main()
{
    double max = std::numeric_limits<double>::max();
    double min = std::numeric_limits<double>::min();
    double inf = std::numeric_limits<double>::infinity();
 
    if (inf > max)
        std::cout << inf << " is greater than " << max << '\n';
}
```

## Sorting an vector of strings

```cpp
struct MyStruct
{
    int key;
    std::string stringValue;

    MyStruct(int k, const std::string& s) : key(k), stringValue(s) {}
};

struct less_than_key
{
    inline bool operator() (const MyStruct& struct1, const MyStruct& struct2)
    {
        return (struct1.key < struct2.key);
    }
};

std::vector < MyStruct > vec;

vec.push_back(MyStruct(4, "test"));
vec.push_back(MyStruct(3, "a"));
vec.push_back(MyStruct(2, "is"));
vec.push_back(MyStruct(1, "this"));

std::sort(vec.begin(), vec.end(), less_than_key());
```

```c++11
#include <vector>
#include <algorithm>

using namespace std;

vector< MyStruct > values;

sort( values.begin( ), values.end( ), [ ]( const MyStruct& lhs, const MyStruct& rhs )
{
   return lhs.key < rhs.key;
});
```
```c++14
#include <vector>
#include <algorithm>

using namespace std;

vector< MyStruct > values;

sort( values.begin( ), values.end( ), [ ]( const auto& lhs, const auto& rhs )
{
   return lhs.key < rhs.key;
});
```



## finding a word in sentence 

```cpp
if (s1.find(s2) != std::string::npos) {
    std::cout << "found!" << '\n';
}
```

## Tokenization in C++

```cpp
    stringstream tokens(sentence);
    string intermediate;
    
    while(getline(tokens, intermediate, ' '))
    {
        if (intermediate.size() > 0) wordList.push_back(intermediate);
    }
```

If the tokenizer is a space then the code below also works fine:

```cpp
while (ss >> Word){
}

where ss is stringstream and word is a temporary string here.
```

## Heap in CPP is by default a MAX Heap.

```cpp
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, lambda for comparator> minHeap;

General Operation:
==================
- push()
- top()
- pop()
- make_heap()
```

## Queue in C++ for  
- queue::empty()	O(1)
- queue::size()	O(1)
- queue::emplace()	O(1)
- queue::front()	O(1)
- queue::back()	O(1)
- queue::push(g) 	O(1)
- queue::pop() 	O(1)

## Sorting a custom object in C++

```cpp
std::vector<Node> v = {
        {"Barack", "Obama"}, {"George", "Washington"}, {"George", "Bush"},
        {"Abraham", "Lincoln"}, {"John", "Tyler"}, {"John", "Kennedy"}
    };
 
    std::sort(v.begin(), v.end(),
            [](const Node &x, const Node &y) {
                // compare last names first
                if (x.last_name != y.last_name) {
                    return x.last_name < y.last_name;
                }
 
                // compare first names only if the last names are equal
                return x.first_name < y.first_name;
            });
 ```
 
 
