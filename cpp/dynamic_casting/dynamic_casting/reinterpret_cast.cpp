#include<iostream>
#include<exception>

using namespace std;

class human{};
class dog{};

int main()
{
	human *pb = new human;
	dog *pd = reinterpret_cast<dog *>(pb);


	//code compiles, but hardly makes any sense, because bith classes are unrelated and derefernce of pd is unsafe.
	return 0;
}
