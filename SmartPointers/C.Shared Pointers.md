# Shared Pointers

std::shared_ptr shares ownership of the resource. They have two handles: one for the resource, and one for the reference counter. By copying an std::shared_ptr, the reference count is increased by one. It is decreased by one if the std::shared_ptr goes out of scope. If the reference counter becomes the value 0, the C++ runtime automatically releases the resource, since there is no longer an std::shared_ptr referencing the resource. The release of the resource occurs exactly when the last std::shared_ptr goes out of scope. The C++ runtime guarantees that the call of the reference counter is an atomic operation. Due to this management, std::shared_ptr consumes more time and memory than a raw pointer or std::unique_ptr.

Take a look at the image below to better visualize the concept.

![image](https://user-images.githubusercontent.com/33947539/186347034-df4996b3-39f3-4403-9ce5-5d05d957d039.png)

Due to shared1, shared2 is initialized. In the end, the reference count is 2 and both smart pointers have the same resource.

## Methods

In the following table, we will see the methods of std::shared_ptr.

![image](https://user-images.githubusercontent.com/33947539/186347158-c00e42a7-7b6a-4745-8713-2db6a59fc33a.png)


## std::make_shared#
The helper function std::make_shared creates the resource and returns it in an std::shared_ptr. Use std::make_shared rather than directly creating an std::shared_ptr because std::make_shared is much faster. Additionally, such as in the case of std::make_unique, std::make_shared guarantees no memory leaks.

## std::shared_ptr from this#
This unique technique, in which a class derives from a class template having itself as a parameter, is called CRTP and stands for Curiously Recurring Template Pattern.

Using the class std::enable_shared_from_this, we can create objects that return an std::shared_ptr to themselves. To do so, we must publicly derive the class from std::enable_shared_from_this. So the class ShareMe support the method shared_from_this, and return std::shared_ptr:

```cpp
// enableShared.cpp

#include <iostream>
#include <memory>

class ShareMe: public std::enable_shared_from_this<ShareMe>{
public:
  std::shared_ptr<ShareMe> getShared(){
    return shared_from_this();
  }
};

int main(){

  std::cout << std::endl;

  std::shared_ptr<ShareMe> shareMe(new ShareMe);
  std::shared_ptr<ShareMe> shareMe1= shareMe->getShared();
  {
    auto shareMe2(shareMe1);
    std::cout << "shareMe.use_count(): "  << shareMe.use_count() << std::endl;
  }
  std::cout << "shareMe.use_count(): "  << shareMe.use_count() << std::endl;
  
  shareMe1.reset();
  
  std::cout << "shareMe.use_count(): "  << shareMe.use_count() << std::endl;

  std::cout << std::endl;

}
```
The smart pointer shareMe (line 17) is copied by shareMe1 (line 18) and shareMe2 (line 20), and all of them

reference the very same resource.
increment and decrement the reference counter.
The call shareMe->getShared() in line 18 creates a new smart pointer. getShared() (line 9) internally uses the function shared_from_this.

## Example 1

```cpp
// sharedPtr.cpp

#include <iostream>
#include <memory>

using std::shared_ptr;

struct MyInt{
  MyInt(int v):val(v){
    std::cout << "  Hello: " << val << std::endl;
  }
  ~MyInt(){
    std::cout << "  Good Bye: " << val << std::endl;
  }
  int val;
};

int main(){

  std::cout << std::endl;

  shared_ptr<MyInt> sharPtr(new MyInt(1998));
  std::cout << "    My value: " << sharPtr->val << std::endl;
  std::cout << "sharedPtr.use_count(): " << sharPtr.use_count() << std::endl;


  {
    shared_ptr<MyInt> locSharPtr(sharPtr);
    std::cout << "locSharPtr.use_count(): " << locSharPtr.use_count() << std::endl;
  }
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;

  shared_ptr<MyInt> globSharPtr= sharPtr;
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;
  globSharPtr.reset();
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl;

  sharPtr= shared_ptr<MyInt>(new MyInt(2011));

  std::cout << std::endl;
  
}
```
### Explanation #
In line 22, we create MyInt(1998), which is the resource that the smart pointer should address. By using sharPtr->val, we have direct access to the resource (line 23).

The output of the program shows the number of references counted. It starts in line 24 with 1. It then has a local copy shartPtr in line 28 and goes to 2. The program then returns to 1 after the block (lines 27-30).

The copy assignment call in line 33 modifies the reference counter. The expression sharPtr= shared_ptr<MyInt>(new MyInt(2011) in line 38 is more interesting.

First, the resource MyInt(2011) is created in line 38 and assigned to sharPtr. Consequently, the destructor of sharPtr is invoked. sharedPtr was the exclusive owner of the resource new MyInt(1998) (line 22).

The last new resource MyInt(2011) will be destroyed at the end of main.
  
## Cyclic Reference
This example demonstrates cyclic references when using std::shared_ptr.

```cpp
 // cyclicReference.cpp

#include <iostream>
#include <memory>

struct Son;
struct Daughter;

struct Mother{
  ~Mother(){                //line 10
    std::cout << "Mother gone" << std::endl;
  }
  void setSon(const std::shared_ptr<Son> s ){
    mySon=s;
  }
  void setDaughter(const std::shared_ptr<Daughter> d ){
    myDaughter=d;
  }
  std::shared_ptr<const Son> mySon;
  std::weak_ptr<const Daughter> myDaughter;
};

struct Son{
  Son(std::shared_ptr<Mother> m):myMother(m){}
  ~Son(){                  //line 25
    std::cout << "Son gone" << std::endl;
  }
  std::shared_ptr<const Mother> myMother;
};

struct Daughter{
  Daughter(std::shared_ptr<Mother> m):myMother(m){}
  ~Daughter(){
    std::cout << "Daughter gone" << std::endl;
  }
  std::shared_ptr<const Mother> myMother;
};

int main(){
  std::cout << std::endl;
  {
    std::shared_ptr<Mother> mother= std::shared_ptr<Mother>( new Mother);   //line 41
    std::shared_ptr<Son> son= std::shared_ptr<Son>( new Son(mother) );
    std::shared_ptr<Daughter> daughter= std::shared_ptr<Daughter>( new Daughter(mother) );
    mother->setSon(son);
    mother->setDaughter(daughter); //line 47
  }
  std::cout << std::endl;
}
```
  
### Explanation #
In line 41 – 47, due to the artificial scope, the lifetime of the mother, the son, and the daughter are limited. In other words, mother, son, and daughter go out of scope, and therefore the destructor of the class Mother (line 10 - 12), Son (line 25 - 27), and Daughter (line 33 - 35) should automatically be invoked.

We state should, because only the destructor of the class Daughter is called.

The graphic of the source code shows that we have a cyclic reference of std::shared_ptr between mother and son. Therefore, the reference counter is always greater than 0, and the destructor will not automatically be invoked.

That observation does not hold true for mother and daughter. If the daughter goes out of scope, the reference counter of the std::shared_ptr myMother (line 36) becomes 0 and the resource will automatically be deleted.  
