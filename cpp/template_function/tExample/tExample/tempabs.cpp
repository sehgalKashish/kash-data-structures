#include<iostream>

using namespace std;

template <class kashish>
kashish abs(kashish n1)
{
	cout<<"\n inside function template...";
	return (n1 < 0) ? -n1:n1;
}

int main()
{
	int int1 = 5;
	int int2 = -6;
	long lon1 = 7000L;
	long lon2 = -23324L;
	double dub1 = 9.94;
	double dub2 = -10.15;

	cout<< "\n abs("<<int1<<")="<<abs(int1);	//abs(int)
	cout<< "\n abs("<<int2<<")="<<abs(int2);	//abs(int)
	cout<< "\n abs("<<lon1<<")="<<abs(lon1);	//abs(long)
	cout<< "\n abs("<<lon2<<")="<<abs(lon2);	//abs(long)
	cout<< "\n abs("<<dub1<<")="<<abs(dub1);	//abs(double)
	cout<< "\n abs("<<dub2<<")="<<abs(dub2);	//abs(double)
	return 0;
}

