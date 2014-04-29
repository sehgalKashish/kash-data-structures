#include"cmp.h"

Complex::Complex()
{
	cout<<"\n in default constructor...";
	n_real = 0;
	n_imag = 0;
}
Complex::Complex(int r)
{
	cout<<"\n in one param constructor..";
	n_real = r;
	n_imag = 0;
}
Complex::Complex(int i, int r)
{
	cout<<"\n in param constructor...";
	n_imag = i;
	n_real = r;
}
void Complex::SetReal()
{
	cout<<"\n enter real part: ";
	cin>>n_real;
}
void Complex::SetImag()
{
	cout<<"\n enter Imaginary part: ";
	cin>>n_imag;
}
int Complex::GetReal()
{
	return n_real;
}
int Complex::GetImag()
{
	return n_imag;
}
Complex Complex::operator+(Complex c2)
{
	Complex temp;
	temp.n_real = n_real + c2.n_real;//return by creating additional dummy object
	temp.n_imag = n_imag + c2.n_imag;
	return temp;
	/*int r, i;
	r = n_real + c2.n_real;
	i = n_imag + c2.n_imag;	//retunr without dummy 
	return Complex(r,i);*/
}
Complex Complex::operator+(int n)
{
	Complex temp;
	temp.n_real = n_real + n;
	temp.n_imag = n_imag + 0;
	return temp;
}
Complex::operator int()
{
	return this->n_real;
}
void Complex::Display()
{
	cout<<"\n in display....";
	cout<<"\n n_real: "<<n_real;
	cout<<"\n n_imag: "<<n_imag;
}
istream&::operator>>(istream &i, Complex &c)
{
	i>>c.n_real;
	i>>c.n_imag;
	return i;
}
ostream&::operator <<(ostream &o, Complex &c)
{
	o<<"real no: "<<c.n_real;
	o<<"imaginary no: "<<c.n_imag;
	return o;

}
Complex::~Complex()
{
	cout<<"\n def destructor...";
}
Complex operator+(int r, Complex c2)
{
	Complex temp;	//creatioon of this dummy opject is required; global functions dont have this pointer.
	temp.n_real = r + c2.n_real;
	temp.n_imag = c2.n_imag;
	return temp;
}
