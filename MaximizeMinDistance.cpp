#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int mid,int arr[], int n, int k)
{
	int pos=arr[0];
	int elements=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]-pos>=mid)
		{
			pos=arr[i];
			elements++;
			if(elements==k)
			{
				return true;
			}
		}
	}
	return false;
}

int LargestMinDistance(int arr[],int n,int k)
{
	int mid;
	sort(arr,arr+n);
	int result=-1;
	int left=arr[0];
	int right=arr[n-1];
	while(left<right)
	{
		mid=(left+right)/2;
		if(isFeasible(mid,arr,n,k))	//if is feasible then search in right part
		{
			result=max(result,mid);
			left=mid+1;
			
		}else{						// else in left part
			right=mid;
		}
	}
	return result;
}

int main()
{
	int arr[6]={2,4,5,6,3,8};		//{5,2,3,4,6,8}
	int res=LargestMinDistance(arr,6,4);
	cout<<res<<" "<<endl;
	return 0;
}
