#include<iostream>

using namespace std;

class Point
{
public:
	double x;
	double y;
};
void offset(Point &p, double x, double y);//pass by refernce, original value gets changed.
//void offset(Point p, double x, double y);//passed by value, copy is created.
int main()
{
	Point p1;
	p1.x = 3;
	p1.y = 4;
	offset(p1, 5, 5);//p1, object of class Point passed.
	cout<<"values of x and y are :"<<p1.x<<" "<<p1.y;
}
/*p passed by reference. original value gets changed*/
void offset(Point &p, double x, double y)
{
	p.x +=x;
	p.y +=y;
}
/* object p passed by value. original value is not changed*/
void offset(Point p, double x, double y)
{
	p.x +=x;
	p.y +=y;
}