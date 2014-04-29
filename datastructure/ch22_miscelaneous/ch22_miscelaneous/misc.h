/*These are programs for ch:22*/

#include<iostream>
using namespace std;
class miscellaneous
{
	int i, j;
public: 
	miscellaneous();
	miscellaneous(int a, int b);
	void set1Val();
	void set2Val();
	void set1Val(int a);
	void set2Val(int a);
	int get1Val();
	int get2Val();
	void And(int i, int j);/* performs bitwise AND operation*/
	void Or(int i, int j);/* perform bitwise OR operation*/
	void Xor(int i, int j);/*perform bitwise Xor operation*/
	void Not(int i);/*perform bitwise Not operation*/
	void LShift(int i, int j);/*perform bitwise left shift*/
	void RShift(int i, int j);/*perform bitwise right shift*/
	void checkNBit(int i, int j);/*to check whether Nth bit is set or not*/
	void setNBit(int i, int j);/*to set the Nth bit*/
	void clearNBit(int i, int j);/*to clear Nth bit*/
	void toggleNBit(int i, int j);/*to toggle Nth bit*/
	void toggleRightMostOneBit(int i);/*to toggle right most 1 bit*/
	void isolateRightMostOneBit(int i);/*to isolate right most one but*/
	void ifPowerOf2(int i);/*if no. is power of two or not*/
	void Display();
};

