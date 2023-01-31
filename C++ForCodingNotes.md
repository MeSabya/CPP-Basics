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
 
 
