***Use the perfect factory method in the code below and make a variadic template to use it with different types.***

## Problem 
```cpp
#include <iostream>
#include <string>
#include <utility>

template <typename T, typename T1>
T create(T1&& t1){
  return T(std::forward<T1>(t1));
}

int main(){

  std::cout << std::endl;

  // Lvalues
  int five=5;
  int myFive= create<int>(five);
  std::cout << "myFive: "  << myFive << std::endl;

  std::string str{"Lvalue"};
  std::string str2= create<std::string>(str);
  std::cout << "str2: " << str2 << std::endl;

  // Rvalues
  int myFive2= create<int>(5);
  std::cout << "myFive2: " << myFive2 << std::endl;

  std::string str3= create<std::string>(std::string("Rvalue"));
  std::cout << "str3: " << str3 << std::endl;

  std::string str4= create<std::string>(std::move(str3));
  std::cout << "str4: " << str4 << std::endl;

  std::cout << std::endl;

};
```
## Solution
```cpp
#include <string>
#include <utility>
#include <initializer_list>
#include <vector>
#include <iostream>

template <typename T, typename ... Arg>
T createT(Arg&& ... arg){
  return T(std::forward<Arg>(arg) ... );
}

int main(){

  int lValue= createT<int>(1);
  int i= createT<int>(lValue);
  std::cout << "lvalue = " << lValue;
  std::cout<< " " <<std::endl;

  std::cout << "i = " << i;
  std::cout<< " " <<std::endl;

  std::string s= createT<std::string>("Only for testing purpose.");
  std::cout << s;
  std::cout<< " " <<std::endl;

  typedef std::vector<int> IntVec;
  IntVec intVec= createT<IntVec>(std::initializer_list<int>({1, 2, 3, 4, 5}));
    for (auto i = intVec.begin(); i != intVec.end(); ++i) 
    std::cout << *i << " ";
}
```

## Explanation #
The three dots in line 9 (std::forward<Args>(args)...) cause each constructor call to perform perfect forwarding. The result is impressive.

Now, we can invoke the perfect factory method with the number of arguments we want, as seen in lines 15, 22, and 27.

