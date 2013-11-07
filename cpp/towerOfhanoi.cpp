/********** Tower Of Hanoi**********/
#include<iostream>

using namespace std;

void toh(int n, char srcPeg, char destPeg, char auxPeg);

int main()
{
	int n;
	char srcPeg, auxPeg, destPeg;
	cout<<"enter the no. of disks";
	cin>>n;
	cout<<"\nenter the names of the pegs";
	cin>>srcPeg>>auxPeg>>destPeg;
	toh(n,srcPeg,destPeg,auxPeg);
	return 0;
}

void toh(int n, char srcPeg, char destPeg, char auxPeg)
{
	if(n == 1)
	{
		cout<<"\nmove disk 1 from "<<srcPeg<<" to "<<destPeg<<"\n";
		return;
	}

	toh(n-1,srcPeg,auxPeg,destPeg);
	cout<<"\nmoved disk "<<n<<" from "<<srcPeg<<" to "<<destPeg<<"\n";
	toh(n-1,auxPeg,destPeg,srcPeg);
} 
	
