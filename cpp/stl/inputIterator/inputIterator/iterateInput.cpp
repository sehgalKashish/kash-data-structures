#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>

using namespace std;

int main()
{
	vector<string> v1;
	copy(istream_iterator<string>(cin),//start source all input untilll end of file or error
		istream_iterator<string>(),//end source
		back_inserter(v1));//destination

	sort(v1.begin(), v1.end());

	unique_copy(v1.begin(), v1.end(), //source
		ostream_iterator<string>(cout,"\n")); //copies the vector form begin to end in out put as destination(screen)
}