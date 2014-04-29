#include<iostream>
#include<stdio.h>
#include"misc.h"

using namespace std;

int main()
{
	miscellaneous m1(8, 5),m2, m3;
	if (m1.get1Val()>m1.get2Val())
		cout<<"i is greater than j";
	m1.Display();
	m1.And(4, 5);
	m1.Or(4, 5);
	m1.Xor(7, 7);
	m1.Not(8);
	m1.LShift(-8, 2);
	m1.RShift(-8, 2);
	m1.checkNBit(12, 4);
	m1.setNBit(12, 1);
	m1.clearNBit(15,2);
	m1.toggleNBit(17,1);
	m1.toggleRightMostOneBit(22);
	m1.isolateRightMostOneBit(16);
	m1.ifPowerOf2(16);
	cin.get();
}