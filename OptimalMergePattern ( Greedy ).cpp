#include<bits/stdc++.h>
using namespace std;

int OptimalMergePattern(vector<int> a,int n)
{
	priority_queue<int,vector<int>,greater<int>>minHeap;
	for(int i=0;i<n;i++)
	{
		minHeap.push(a[i]);
	}
	int ans=0;
	while(minHeap.size()>1)
	{
		int e1=minHeap.top();
		minHeap.pop();
		int e2=minHeap.top();
		minHeap.pop();
		ans+=e1+e2;
		minHeap.push(e1+e2);
	}
	return ans;
}

int main()
{
	vector<int>a={1,2,3,4};
	int n=a.size();
	for(auto i:a)
		cout<<i<<" ";
	cout<<endl<<OptimalMergePattern(a,n)<<endl;
	return 0;
}
