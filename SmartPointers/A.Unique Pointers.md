# Unique Pointers

Before we go into the usage of std::unique_ptr, here are its characteristics in a few bullet points.

The std::unique_ptr:

- can be instantiated with and without a resource.
- manages the life cycle of a single object or an array of objects.
- transparently offers the interface of the underlying resource.
- can be parametrized with its own deleter function.
- can be moved (move semantics).
- can be created with the helper function std::make_unique.
- Replacement for std::auto_ptr

```cpp
#include <iostream>
#include <memory>
int main(){
  std::auto_ptr<int> ap1(new int(2011));
  std::auto_ptr<int> ap2 = ap1;              // OK

  std::unique_ptr<int> up1(new int(2011));
  //std::unique_ptr<int> up2 = up1;            // ERROR
  std::unique_ptr<int> up3 = std::move(up1); // OK

  return 0;
}
```

## Methods
These are the methods of std::unique_ptr:

![image](https://user-images.githubusercontent.com/33947539/186344336-b749ed73-bfa4-4bfe-bb3f-96638901f43d.png)


## std::make_unique#
The helper function std::make_unique was unlike its sibling std::make_shared, and was “forgotten” in the C++11 standard. Therefore, std::make_unique was added with the C++14 standard. std::make_unique enables us to create an std::unique_ptr in a single step:

```cpp
std::unique_ptr<int> uniqPtr1= std::make_unique<int>(2011);
auto uniqPtr2= std::make_unique<int>(2014);
```

Using std::make_unique in combination with automatic type deduction means typing is reduced to its bare minimum.

👉 ***Always use std::make_unique.***

If we use

```cpp
func(std::make_unique<int>(2014), functionMayThrow());
func(std::unique_ptr<int>(new int(2011)), functionMayThrow());
```
and functionMayThrow throws, we have a memory leak with new int(2011) for this possible sequence of calls:

```cpp
new int(2011)
functionMayThrow()
std::unique_ptr<int>(...)
```
Rarely, when we create std::unique_ptr in an expression and the compiler optimizes this expression, a memory leak may occur with an std::unique_ptr call. Using std::make_unique guarantees that no memory leak will occur.

Under the hood, std::unique_ptr uses the perfect forwarding pattern. The same holds for the other factory methods such as std::make_shared, std::make_tuple, std::make_pair, or an std::thread constructor.




