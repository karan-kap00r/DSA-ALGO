#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
bool vis[N];
vector<int> adj[N];

void PreDFS(int node)
{
	vis[node]=1;
	cout<<node<<" ";
	vector<int>::iterator it;
	for(it =adj[node].begin();it!=adj[node].end();it++)
	{
		if(vis[*it]);
		else
		PreDFS(*it);
	}
}

int main()
{
	memset(vis,0,sizeof(vis));
	cout<<"Enter number of verticies and edges :"<<endl;
	int n,m;cin>>n>>m;
	int x,y;
	cout<<"Enter linked verticies :"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout<<endl<<"DFS of given graph is : "<<endl;
	PreDFS(1);
	return 0;
}
