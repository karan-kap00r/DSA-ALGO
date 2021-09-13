#include<bits/stdc++.h>
using namespace std;

void MinimumCoin(vector<int> a,int X)
{
	sort(a.begin(),a.end(),greater<int>());
	int ans=0;
	for(int i=0;i<a.size();i++)
	{
		ans+=(X/a[i]);
		X-=(X/a[i])*a[i];
	}
	cout<<ans<<endl;
}
int main()
{
	vector<int>arr={1,2,5,10,20,50,100,200,500,2000};
	int x;
	cout<<"DENOMINATIONS ARE: "<<endl;
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"Enter the value of X : "<<endl;
	cin>>x;
	MinimumCoin(arr,x);
	return 0;
}
