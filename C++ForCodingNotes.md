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


