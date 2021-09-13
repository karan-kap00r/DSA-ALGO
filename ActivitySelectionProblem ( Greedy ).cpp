#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the value of N : "<<endl;
	cin>>n;
	vector<vector<int>> v;
	cout<<"Enter the start-end time pair"<<endl;
	for(int i=0;i<n;i++)
	{
		int start,end;
		cin>>start>>end;
		v.push_back({start,end});
	}
	
	sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){			//Comparator
		return (a[1]<b[1]);
	});
	
	int take=1;
	int end=v[0][1];
	for(int i=0;i<n;i++)
	{
		if(v[i][0]>=end)
		{
			take++;
			end=v[i][1];
		}
	}
	cout<<"Maximum activities done in given time is : "<<take<<endl;
	return 0;
}
