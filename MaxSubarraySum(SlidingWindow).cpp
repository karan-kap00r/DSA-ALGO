//	MAX Sum in K sized Subarray using Sliding Window and 2-Pointer's Algorithm:

#include<bits/stdc++.h>
using namespace std;

void MaxSum(int arr[],int n,int k,int x)
{
	int sum=0, ans=0;
	
	for(int i=0;i<k;i++)
		sum+=arr[i];
	if(sum<x)
		ans=sum;
	for(int i=k;i<n;i++)
	{
		sum=sum-arr[i-k];		//Sliding Window technique
		sum=sum+arr[i];
		
		if(sum<x)
			ans=max(ans,sum);
	}
	cout<<ans<<" is the max subarray sum "<<endl;
}

int main()
{
	int arr[6]={-1,0,3,5,2,-4};
	int k=3,x=10;
	MaxSum(arr,6,k,x);
	return 0;
}
