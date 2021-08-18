#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
	if(n==0)
	return 0;
	if(n==1)
	return 1;
	return (fib(n-1)+fib(n-2));
}
int main()
{
	int c;
	cout<<"FIBONACCI NUMBER"<<endl;
	cout<<"enter a number : "<<endl;
	cin>>c;
	int x=fib(c);
	cout<<" "<<x;
	return 0;
}
