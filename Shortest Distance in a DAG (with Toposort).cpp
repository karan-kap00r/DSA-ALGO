#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2,MOD=1e9+7;
vector<pair<int,int> > adjL[N];
stack<int> st;
bool vis[N];

void AdjList(int n,int m)         //   GRAPH USING ADJACENCY LIST
{
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adjL[x].push_back({y,w});
        // adjL[y].push_back(x);
    }
    
}

void DFS(int n,vector<int> &vis)
{
    
    vis[n]=1;

    for(auto i:adjL[n])
    {
        if(!vis[i.first])
        {
            vis[i.first]=1;
            DFS(i.first,vis);
        }
    }
    st.push(n);
    return;
}

void helper(int src,vector<int> &din)
{

        din[src]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();   
        if(din[node]!=INT_MAX)
        {
        for(auto i:adjL[node])
        {
            if(din[node]+i.second < din[i.first])
            din[i.first]=din[node]+i.second;
        }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
   
    vector<int> vis(n,0),din(n,INT_MAX);
    AdjList(n,m); 
    for(int i=0;i<n;i++) 
    {
        if(!vis[i])
            DFS(0,vis);
    }
    helper(0,din);
    for(auto i:din)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

