//Breadth First Search 

#include<bits/stdc++.h>
using namespace std;

//GLOBAL VARIABLES
const int N=1e5+2,MOD=1e9+7;
vector<int> adj[N];			//adjacency list vector
bool vis[N];				//bool array

int main()
{
	memset(vis,0,sizeof(vis));		//initialize boolean array with 0
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}						//Adjacency list formed
	
	queue<int> q;			//queue
	q.push(1);
	vis[1]=true;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		cout<<node<<" ";			//print the front of the queue
		for(auto it=adj[node].begin();it!=adj[node].end();it++)
		{
			if(!vis[*it])			//If Node is not visited
			{
				vis[*it]=1;			//visit it 
				q.push(*it);		//add it to the queue
			}
		}
	}
	return 0;
}
