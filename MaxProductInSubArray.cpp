#include<bits/stdc++.h>
using namespace std;

int MaxProduct(int arr[],int n)
{
	int rof=INT_MIN;
	int mul=1;
	for(int i=0;i<n;i++)
	{
		mul=mul*arr[i];
		if(mul<1)
		{
			mul=1;
		}
		rof=max(mul,rof);
	}
	return rof;
}



int main()
{
	int arr[5]={9,-2,-2,7,2};
	cout<<"ARRAY IS : "<<endl;
	for(int s:arr)
	cout<<s<<" ";
	int x=MaxProduct(arr,5);
	cout<<endl<<"maximum product in the subarray is "<<endl<<x;
	return 0;
}
