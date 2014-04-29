/**
*In the following example, few c++ concepts have been explained.
*like, Operator overlaoding, function overlaoding, constructor, destructor
*<< >> operator overloading.
*one param constructor
*overlaoding int() operator
**/

#include<iostream>

using namespace std;

//friend Complex operator+(int r, Complex c1);

class Complex
{
	int n_imag, n_real;
public:
	Complex();
	Complex(int i);
	Complex(int i, int r);
	void SetReal();
	void SetImag();
	int GetReal();
	int GetImag();
	Complex operator+(Complex c2);//+ operator overloading
	Complex operator+(int n);//single param, l-value comes itself.
	operator int();/* conversion from class to basic.*/
	friend ostream& operator<<(ostream &o, Complex &c1);// over loading extraction operator to return refernce.
	friend istream& operator>>(istream &i, Complex &c1);//overloading insertion operator to return refernce.
	friend Complex operator+(int i, Complex c2);//2 param, both must be fetched.
	void Display();
	~Complex();
};
