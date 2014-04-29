
#include"cmp.h"

int main()
{
	Complex c1;
	Complex c2, c3;
	//c2.SetReal();
	//c2.SetImag();
	//cout<<"\n C2 ka display call liya..";
	//c2.Display();
	//Complex c1 = c2;
	//cout<<"\n C1 ka display call liya after c1 = c2..";
	//c1.Display();
	//c3 = c1 + c2;//c1.operator+(c2); this is how the call is made
	//cout<<"\n C3 ka display call liya after c1.operator + c2..";
	//c3.Display();
	//c3 = c3 + 2;
	//cout<<"\n C3 ka display call liya after c3.operator + 2..";
	//c3.Display();
	//c3 = 3 + c2;//int operator+ c3; since we can't access private members directly overloading can't be directly done.
				//therefore we have used friend function
	cout<<"\n enter c4 :";
	Complex c4;
	cin>>c4;

	cout<<"\n the val of c4 is : "<<c4;//cout.operator <<(c3);.its kind of 2+c3, 
										//since object of ostrean can't be created, singleton pattern.
										//but refernces are allowed ;)
	c2 = 5;/*type connversion, from Basic(int) to class(Complex)
		   here LHS is destination, and RHS is source.
		   Write one-parameter constructor for this.
		   */
	cout<<c2;

	int i;
	i = c4; /**type conversion from Class(Complex) to basic (int)
			* but we can't write constructor in basic class, since
			* int is built in class.
			* but we can do is overload int() operator
			* here we assume that only first 4 bytes get allocated, rest are 
			* lost due to precision
			**/
	cout<<"\n value of i is: "<<i;

}