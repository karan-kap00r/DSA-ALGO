#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2,MOD=1e9+7;
vector<int> adjL[N];
bool vis[N];

void AdjList(int n,int m)         //   GRAPH USING ADJACENCY LIST
{
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adjL[x].push_back(y);
        // adjL[y].push_back(x);
    }
    // cout<<"Adjacency List is given by:"<<endl;
    // for(int i=1;i<n+1;i++)
    // {
    //     cout<<i<<" --> ";
    //     for(auto j:adjL[i])
    //         cout<<j<<" ";
    //     cout<<endl;
    // }
}

stack<int> st;

void DFS(int node,vector<int> &vis)
{
    vis[node]=1;
    for(auto i:adjL[node])
    {
        if(!vis[i])
        {
            DFS(i,vis);
        }
    }
    st.push(node);
    return ;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> vis(n,0),dfsvis(n,0);
    
    AdjList(n,m);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        DFS(i,vis); 
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}

