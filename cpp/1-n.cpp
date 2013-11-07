#include<stdio.h>
#include<iostream>

using namespace std;

void Print(int N);

int main()
{
        int n;
        cout<<"enter the no.";
        cin>>n;
        Print(n);
        return 0;
}

void Print(int n)
{
        if(n == 0)
                return;
        else
        {
                Print(n-1);
                cout<<"\n"<<n;
        }
        return;
}

