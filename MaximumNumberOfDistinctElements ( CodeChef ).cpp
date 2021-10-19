#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(pair<ll,ll> &a,pair<ll,ll> &b)
{
	return a.second < b.second;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n;
		vector<pair<ll,ll> > arr;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			arr.push_back(make_pair(x,i));
		}
		ll k=0;
		sort(arr.begin(),arr.end());
		for(int i=0;i<n;i++)
		{
			if(arr[i].first > k)
			{
				arr[i].first=k;
				k++;
			}
			else if(arr[i].first==k)
			arr[i].first=k;
		}
		sort(arr.begin(),arr.end(),cmp);
		for(int i=0;i<n;i++)
			cout<<arr[i].first<<" ";
		cout<<endl;
	}
}
