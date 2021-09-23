#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;			//vertices,edges
	
	vector<vector<int>>adjM(n+1,vector<int>(n+1,0));	//Adjacency Matrix
	for(int i=0;i<m;i++)
	{
		int x,y;			//2 verticies having direct edge
		cin>>x>>y;
		adjM[x][y]=1;	
		adjM[y][x]=1;		//Undirected Graph
	}
	cout<<"Adjacency Matrix of given graph is : "<<endl;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
			cout<<adjM[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
