//	Minimum size Subarray having maxSum using Sliding Window and 2-Pointer's Algorithm:

#include<bits/stdc++.h>
using namespace std;

int SmallestSubarray(int arr[],int n,int x)
{
	int sum=0, minLength=n+1;
	int start=0,end=0;
	while(end<n)
	{
		while(sum <= x && end < n)
			sum+=arr[end++];
		while(sum > x && start < n)
		{
			if(end-start < minLength)
			{
				minLength = end-start;
			}
			sum-=arr[start++];
		}
	}
	return minLength;
}
int main()
{
	int arr[6]={1,4,45,6,10,19};
	int x=51;
	cout<<SmallestSubarray(arr,6,x)<<" is the size of Subarray having maximum sum";
	return 0;
}
