#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> myVec;
	vector<int>::iterator po;

	myVec.push_back(4);
	myVec.push_back(2);
	myVec.push_back(7);
	myVec.push_back(8);
	myVec.push_back(9);
	myVec.push_back(5);
	myVec.push_back(0);

	po = min_element(myVec.begin(), myVec.end());//find min element
	cout<<"\n the min element is : "<<*po;
	po = max_element(myVec.begin(), myVec.end());//find max element
	cout<<"\n the max element is : "<<*po;

	sort(myVec.begin(), myVec.end());

	for(po = myVec.begin(); po!=myVec.end(); po++)
	{
		cout<<"\n element is : "<<*po;
	}

	po = find(myVec.begin(), myVec.end(), 7);//find a specif element

	reverse(po, myVec.end());

	for(po; po!=myVec.end(); po++)
	{
		cout<<"\n element is : "<<*po;
	}

}
