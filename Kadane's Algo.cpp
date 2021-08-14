// C++ program to print largest contiguous array sum 
//KADANE's ALGORITHM

#include<bits/stdc++.h>
using namespace std; 
  
int LargestSubArray(int arr[],int size)
{
	int max1=0;
	int max2=0;
	for(int i=0;i<size;i++)
	{
		(max2=max2+arr[i]);
		if(max2<0)
		max2=0;
		if(max1<max2)
		max1=max2;
	}
	return (max1);
}

int main()
{
	int n;
	cout<<"enter the size of an array";
	cin>>n;
	int a[n];
	cout<<"enter the elements of an array";
	for(int j=0;j<n;j++)
	{
		cin>>a[j];
	}
	for(int k=0;k<n;k++)
	{
		cout<<"  "<<a[k];
	}
	int max_sum=LargestSubArray(a,n);
	cout<<endl<<"the largest sum of a contigious array is"<<max_sum;
	return(0);
}
