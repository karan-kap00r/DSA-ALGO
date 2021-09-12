#include<bits/stdc++.h>
using namespace std;

void DivisibleByThree(vector<int> arr,int k)
{
	pair<int,int> ans;
	int sum=0;
	for(int i=0;i<k;i++)
		sum+=arr[i];
	bool found=false;
	if(sum%3==0)
		found = true;
	for(int i=k;i<arr.size();i++)
	{
		if(found)
			break;
		
		sum=sum+arr[i]-arr[i-k];		//Sliding Window Technoque
		if(sum%3==0)
		{
			ans=make_pair(i-k+1,i);
			found = true;
		}
	}
	if(! found)
		ans=make_pair(-1,0);
	if(ans.first==-1)
		cout<<"No such subarray exists"<<endl;
	else
	{
		for(int i=ans.first;i<=ans.second;i++)
			cout<<arr[i]<<" ";
	}
}
int main()
{
	vector<int> a={2,5,6,4,2,9};
	DivisibleByThree(a,4);
	return 0;
}
