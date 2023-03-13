## Uses of Initializer List in C++

### When no Base class default constructor is present

### When reference type is used

```cpp
#include<iostream>
using namespace std;

class Base
{
    private:
    int &ref;
    public:
    Base(int &ref):ref(ref)
    {
        cout << "Value is " << ref;
    }
};

int main()
{
    int ref=10;
    Base il(ref);
    return 0;
}
```

### For initializing const data member

const data members can be initialized only once, so it must be initialized in the initialization list.

### When data member and parameter have same name

### For improving performance

If you are assigning the values inside the body of the constructor, then a temporary object would be created which will be provided to the assignment operator. The temporary object will be destroyed at the end of the assignment statement. Creation of temporary object can be avoided by using initializer list.

## Order of execution in initializer list in C++
https://www.geeksforgeeks.org/order-of-execution-in-initializer-list-in-c/
