#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	//typedef multimap<int,string> intStringMultiMap;//duplicate enteries are allowed. stored in order
	typedef map<int,string> intStringMultiMap;//duplicate enteries not allowed.
	//typedef map<string,string> intStringMultiMap;//duplicate enteries not allowed.
	intStringMultiMap mm;
	
	mm.insert(make_pair(3,"tagged"));	//stored according to first element.sorted order.
	mm.insert(make_pair(2,"untagged"));
	mm.insert(make_pair(7,"robin"));
	mm.insert(make_pair(3,"backd"));
	mm.insert(make_pair(5,"comeoned"));
	mm.insert(make_pair(0,"rughr"));
	mm.insert(make_pair(2,"we willd"));

	intStringMultiMap::const_iterator po;
	for(po=mm.begin(); po!=mm.end(); po++)
	{
		cout<<"the map elemensta are: "<<po->first<<"|| "<<po->second<<endl;
	}
}
