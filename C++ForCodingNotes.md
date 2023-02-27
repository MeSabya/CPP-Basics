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
 
 
