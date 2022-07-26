#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2,MOD=1e9+7;
vector<int> adjL[N];

//Formula to check if it is a Bridge or not:	low[adj_node]> time[node]


void AdjList(int n,int m)         //   GRAPH USING ADJACENCY LIST
{
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }
    
}

void DFS(int node,int parent,vector<int> &tin,vector<int> &low,vector<int>&vis,int &timer)
{
    vis[node]=1;
    tin[node]=low[node]=++timer;
    for(auto it: adjL[node])
    {
        if(it==parent)
            continue;
        if(!vis[it])
        {
            DFS(it,node,tin,low,vis,timer);
            low[node]=min(low[node],low[it]);
            if(low[it] > tin[node])               // Formula to check if it is a bridge or not
                cout<<node<<" - "<<it<<endl;
        }
        else if(parent!=it)
            low[node]=min(low[node],tin[it]);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    // vector<int> adjL[n];
    AdjList(n,m);

    vector<int> tin(n,-1),low(n,-1),vis(n,0);
    int timer=0;
    for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                DFS(i,-1,tin,low,vis,timer);
        }
    
    return 0;
}

