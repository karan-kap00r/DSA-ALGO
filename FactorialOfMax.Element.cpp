#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void Display(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<" "<<a[i];
	}
}
int Factorial(int n)
{
	int fac=1;
	for(int i=2;i<=n;i++)
	fac=fac*i;
	cout<<"factorial is "<<fac;
	return fac;
	 
}
int main()
{
	int n;
	cout<<"enter the size of an array";
	cin>>n;
	int a[n];
	cout<<endl<<"enter the elements of an array of size "<<n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	sort(a,a+n);
	cout<<endl;
	Display(a,n);
	cout<<endl;
	Factorial(a[n-1]);
	return 0;
}
