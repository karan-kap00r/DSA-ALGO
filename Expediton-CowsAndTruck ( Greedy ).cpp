#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cout<<"Enter the number of test cases : "<<endl;
	cin>>t;
	while(t--)
	{
		int n;
		cout<<"Enter the value of n : "<<endl;
		cin>>n;
		vector<pair<int,int>>a(n);
		cout<<"Enter the distance-fuel pair values of stops: "<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].first>>a[i].second;
		}
		int l,p;
		cout<<"Enter the values of L and P : "<<endl;
		cin>>l>>p;
//		distance of stop from truck= (distance of truck from town - distance of stop from town)
		for(int i=0;i<n;i++)
		{
			a[i].first=l-a[i].first;
		}
		sort(a.begin(),a.end());
		int ans=0;		//number of fuel stops
		int curr=p;
		priority_queue<int,vector<int>>pq;
		bool flag=0;		//variable for invalid case
		for(int i=0;i<n;i++)
		{
			if(curr>=l)
				break;
			while(curr< a[i].first)
			{
				if(pq.empty())
				{
					flag=1;
					break;
				}
				
				flag=0;
				ans++;
				curr+=pq.top();
				pq.pop();
			}
			if(flag)
				break;
			pq.push(a[i].second);
		}	
    			if(flag)
			{
				cout<<"-1"<<endl;
				continue;
			}
			while(!pq.empty() && curr<l)
			{
				curr+=pq.top();
				pq.pop();
				ans++;
			}
			if(curr<l)
			{
				cout<<"-1"<<endl;
				continue;
			}
		cout<<"Number of fuel stops : "<<ans<<endl;
	}
		return 0;
}
