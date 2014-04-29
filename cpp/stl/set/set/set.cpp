#include<iostream>
#include<set>

using namespace std;

int main()
{
	//typedef std::multiset<int> myset;//allows duplicate enteries, rest is same as set.
	typedef std::set<int> myset;//won't allow duplicate enteries
	myset col;

	col.insert(3);
	col.insert(7);
	col.insert(8);
	col.insert(1);
	col.insert(9);
	col.insert(3);

	myset::const_iterator po;
	for(po=col.begin();po!=col.end();po++)
	{
		cout<<"\n set are :"<<*po<<endl;
	}
}