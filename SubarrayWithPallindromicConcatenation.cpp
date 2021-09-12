#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(int n)
{
	int temp=n,number=0;
	while(temp>0)
	{
		number=number*10 + temp%10;
		temp=temp/10;
	}
	if(number==n)
		return true;
	return false;
}

int PallindromeSubarray(vector<int> arr,int k)
{
	int num=0;
	for(int i=0;i<k;i++)
	{
		num=num*10+arr[i];
	}
	if(isPallindrome(num))
		return 0;
	
	for(int i=k;i<arr.size();i++)
	{
		num=(num%(int)pow(10,k-1))*10+arr[i];
		if(isPallindrome(num))
			return i-k+1;
		
	}
	return -1;
}

int main()
{
	vector<int> a={4,1,2,2,2,2,4};
	int x=PallindromeSubarray(a,3);
	cout<<"Starting index of Pallindromic subarray is : "<<x<<endl;
	return 0;
}
