/*copying contents of list to vector*/

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	list<int> l1;
	vector<int> v1;
	deque<int> d1;
	set<int> s1;

	l1.push_back(23);
	l1.push_back(3);
	l1.push_back(2);
	l1.push_back(213);
	l1.push_back(233);
	l1.push_back(2);
	l1.push_back(253);

	//v1.resize(l1.size());
	d1.resize(l1.size());
	

	//copy(l1.begin(),l1.end(), v1.begin());//copying list to vector
	copy (l1.begin(), l1.end(),back_inserter(v1));      // another way to copy back inserter, resize not used in this case.
            
	vector<int>::const_iterator itr1;
	for(itr1 = v1.begin(); itr1<v1.end(); itr1++)
	{
		cout<<"\n vector : "<<*itr1;
	}

	copy(l1.begin(),l1.end(), d1.begin());//copying list to deque
	deque<int>::const_iterator itr;
	for(itr = d1.begin(); itr<d1.end(); itr++)
	{
		cout<<"\n deque: "<<*itr;
	}

	copy(l1.begin(),l1.end(), inserter(s1,s1.begin()));//copying list to set; inserter works for associative containers.
	deque<int>::const_iterator itr2;
	for(itr2 = d1.begin(); itr2<d1.end(); itr2++)
	{
		cout<<"\n set: "<<*itr2;
	}
}

