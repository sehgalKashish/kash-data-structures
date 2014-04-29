#include<iostream>
#include<vector>
#include<deque>
#include<list>

using namespace std;

int main()
/*{
	//vector<int> col;		//vector container for int
	deque<double> col;		//deque container for float
	for(int i = 0; i<5; i++)
	{
		//col.push_back(i);
		col.push_front(i*1.1);//
	}
	for(int i=0; i<col.size(); i++)
		cout<<"\n "<<col[i];
}
*/
{
	list<char> lst;
	for(char c='a'; c<='z'; c++)
	{
		lst.push_back(c);
	}
	/*while(!lst.empty())
	{
		cout<<"list is "<<lst.front();
		lst.pop_front();
		cout<<endl;
	}*/

	/* using iterator for printing purpose*/
	list<char>::const_iterator pos;
	for(pos = lst.begin(); pos!=lst.end(); pos++)
	{
		cout<<"\n list elements are : " << *pos;
	}
}