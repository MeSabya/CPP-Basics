Sometimes, it is required to convert one concrete type to another concrete type or primitive type implicitly. 

```cpp
// CPP Program to demonstrate Conversion Operators
#include <cmath>
#include <iostream>
using namespace std;

class Complex {
private:
	double real;
	double imag;

public:
	// Default constructor
	Complex(double r = 0.0, double i = 0.0)
		: real(r)
		, imag(i)
	{
	}

	// magnitude : usual function style
	//double mag() { return getMag(); }

	// magnitude : conversion operator
	operator double() {
      cout<<"My conversion operator"<<endl;
      return getMag(); 
    }

private:
	// class helper to get magnitude
	double getMag()
	{
		return sqrt(real * real + imag * imag);
	}
};

int main()
{
	// a Complex object
	Complex com(3.0, 4.0);

	// print magnitude
	//cout << com.mag() << endl;
	// same can be done like this
	cout << com << endl;
}
```


