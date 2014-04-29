#include"misc.h"
#include<iostream>
#include<stdio.h>
#include<bitset>

using namespace std;

miscellaneous::miscellaneous()
{
	i = 0;
	j = 0;
}
miscellaneous::miscellaneous(int a, int b)
{
	i = a; 
	j = b;
}
int miscellaneous::get1Val()
{
	return i;
}
int miscellaneous::get2Val()
{
	return j;
}
void miscellaneous::set1Val()
{
	cout<<"\nEnter the value of 1st no.:";
	cin>>i;
}
void miscellaneous::set2Val()
{
	cout<<"\nEnter the value of 2nd no.:";
	cin>>j;
}
void miscellaneous::set1Val(int a)
{
	i = a;
}
void miscellaneous::set2Val(int a)
{
	j = a;
}
void miscellaneous::And(int i, int j)
{
	cout<<"\n Bitwise AND";
	cout<<"\n\t\t  "<< (bitset<8>) i;
	cout<<"\n\t\t& "<< (bitset<8>) j;
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t  "<< ((bitset<8>) (i&j))<<"\n";
}
void miscellaneous::Or(int i, int j)
{
	cout<<"\n Bitwise OR";
	cout<<"\n\t\t  "<< (bitset<8>) i;
	cout<<"\n\t\t| "<< (bitset<8>) j;
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t  "<< ((bitset<8>) (i|j))<<"\n";
}
void miscellaneous::Xor(int i, int j)
{
	cout<<"\n Bitwise XOR";
	cout<<"\n\t\t  "<< (bitset<8>) i;
	cout<<"\n\t\t^ "<< (bitset<8>) j;
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t  "<< ((bitset<8>) (i^j))<<"\n";
}
void miscellaneous::Not(int i)
{
	cout<<"\n Bitwise NOT";
	cout<<"\n\t\t~ "<< (bitset<8>) i;
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t  "<< ((bitset<8>) (~i))<<"\n";
}
void miscellaneous::LShift(int i, int j)
{
	cout<<"\n Bitwise Left shift";
	cout<<"\n\t\t~ "<< (bitset<8>) i;
	cout<<"\n\t\t <<"<<j;
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t  "<< ((bitset<8>) (i<<j))<<"\n";
}
void miscellaneous::RShift(int i, int j)
{
	cout<<"\n Bitwise RIGHT SHIFT";
	cout<<"\n\t\t~ "<< (bitset<8>) i;
	cout<<"\n\t\t >>"<<j;
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t  "<< ((bitset<8>) (i>>j))<<"\n";
}
void miscellaneous::checkNBit(int i, int j)
{
	if ((i&1<<(j-1)))
		cout<<"\nthe bit was set";
	else
		cout<<"\n sorry, bit was not set";
}
void miscellaneous::setNBit(int i, int j)
{
	cout<<"\n Bitwise SET Nth BIT";
	cout<<"\n\t\t "<< (bitset<8>) i;
	cout<<"\n\t\t "<<j;
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t  "<< (bitset<8>) (i|(1<<(j-1)))<<"\n";
}
void miscellaneous::clearNBit(int i, int j)
{
	cout<<"\n Bitwise CLEAR Nth BIT";
	cout<<"\n\t\t "<< (bitset<8>) i;
	cout<<"\n\t\t "<< j;
	cout<<"\n\t\t "<< (bitset<8>) (~(1<<(j-1)));
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t "<< (bitset<8>) (i&(~(1<<(j-1))))<<"\n";
}
void miscellaneous::toggleNBit(int i, int j)
{
	cout<<"\n Bitwise TOGGLE Nth BIT";
	cout<<"\n\t\t "<< (bitset<8>) i;
	cout<<"\n\t\t "<< j;
	cout<<"\n\t\t "<< (bitset<8>) (~(1<<(j-1)));
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t "<< (bitset<8>) (i^(1<<(j-1)))<<"\n";
}
void miscellaneous::toggleRightMostOneBit(int i)
{
	cout<<"\n Bitwise TOGGLE RIGHT MOST ONE BIT";
	cout<<"\n\t\t "<< (bitset<8>) i;
	cout<<"\n\t\t "<< (bitset<8>) ((i-1));
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t "<< (bitset<8>) (i&(i-1))<<"\n";
}
void miscellaneous::isolateRightMostOneBit(int i)
{
	cout<<"\n Bitwise ISOLATE RIGHT MOST ONE BIT";
	cout<<"\n\t\t "<< (bitset<8>) i;
	cout<<"\n\t\t "<< (bitset<8>) ((-i));
	cout<<"\n\t\t----------------";
	cout<<"\n \t\t "<< (bitset<8>) (i&(-i))<<"\n";
}
void miscellaneous::ifPowerOf2(int i)
{
	cout<<"\n To check whether a no. is power of 2 or not.";
	cout<<"\n\t\t "<<i;
	if(i&(i-1) == 0)
		cout<<"\n no, not power of 2";
	else
		cout<<"\n yes, wow power of 2";
}
void miscellaneous::Display()
{
	cout<<"\nthe value of i is :"<<i<<" and value of j is : "<<j;
}