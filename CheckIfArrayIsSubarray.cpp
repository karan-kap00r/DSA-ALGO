#include<bits/stdc++.h>
using namespace std;

bool SubarrayCheck(int arr[],int brr[],int n,int m)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==brr[0])
		{
			flag++;
			for(int j=1;j<m;j++)
			{
				i++;
				if(arr[i]==brr[j])
				{
					flag++;
				}
				else
				{
					break;
				}
			}
			if(flag==m)
			return true;
			else
			return false;
		}
	}
}

int main()
{
	int arr[7]={1,2,3,4,5,6,7};
	int brr[3]={4,5,6};
	for(int i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for(int j:brr)
	{
		cout<<j<<" ";
	}
	cout<<endl<<"Check if 2nd array is Subarray of 1st array : "<<endl;
	if(SubarrayCheck(arr,brr,7,3))
	cout<<"YES..."<<endl;
	else
	cout<<"NO..."<<endl;
	return 0;
}
