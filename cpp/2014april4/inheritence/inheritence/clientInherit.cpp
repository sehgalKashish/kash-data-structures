#include"inherit.h"

int main()
{
	//Employee e1;
	//Employee e2(5,"raju");
	WageEmployee w1;
	w1.Display();
	WageEmployee w2(6, "Ramesh", 2.3, 4);
	w2.Display();
}