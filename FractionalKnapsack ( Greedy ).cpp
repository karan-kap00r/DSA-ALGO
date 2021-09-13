#include<bits/stdc++.h>
using namespace std;

bool Compare (pair<int,int>p1,pair<int,int>p2)			//Comparator
{
	double v1=(double) p1.first/p1.second;				//Value per unit Weight
	double v2=(double) p2.first/p2.second;
	return v1>v2;
}

int main()
{
	int n;
	cout<<"Enter the value of N : "<<endl;
	cin>>n;
	vector<pair<int,int>>a(n);
	cout<<"Enter the value-weight time pair"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
		
	sort(a.begin(),a.end(),Compare);
	int ans=0,W;
	cout<<"Enter the weight of Knapsack"<<endl;
	cin>>W;
	for(int i=0;i<n;i++)
	{
		if(W>=a[i].second)
		{
			ans+=a[i].first;
			W-=a[i].second;
			continue;
		}
		double vw=(double)a[i].first/a[i].second;
		ans+=vw*W;									//Fractional Part of weight
		W=0;
		break;
	}
	cout<<ans<<endl;
	return 0;
}
