#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2,MOD=1e9+7;
vector<int> adjL[N];

//Formula to check if it is a Articulation Point or not:	(low[adj_node] >= time[node] && (Parent != -1) && (Individual_Child>1))

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

void DFS(int node,int parent,vector<int> &tin,vector<int> &low,vector<int>&vis,int &timer,vector<int> &isArticulation)
{
    vis[node]=1;
    tin[node]=low[node]=timer++;
    int child=0;
    for(auto it: adjL[node])
    {
        if(it==parent)
            continue;
        if(!vis[it])
        {
            DFS(it,node,tin,low,vis,timer,isArticulation);
            low[node]=min(low[node],low[it]);
            if(low[it] >= tin[node] && parent != -1) {              // Formula to check if it is a bridge or not
                isArticulation[node]=1;
            }
            child++;
        }
        else
            low[node]=min(low[node],tin[it]);
    }
    if(parent==-1 && child > 1)
        isArticulation[node]=1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    // vector<int> adjL[n];
    AdjList(n,m);

    vector<int> tin(n,-1),low(n,-1),vis(n,0),isArticulation(n,0);
    int timer=0;
    for(int i=0;i<n;i++)
        {
            if(!vis[i])
                DFS(i,-1,tin,low,vis,timer,isArticulation);
        }
        cout<<"ARTICULATION POINTS ARE:"<<endl;
        for(int i=0;i<n;i++)
        {
            if(isArticulation[i]==1)
                cout<<i<<endl;
        }
    
    return 0;
}

