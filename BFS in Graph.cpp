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
        adjL[y].push_back(x);
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

void BFS(int n,int m)               //BFS TRAVERSAL
{
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        vector<int> :: iterator it=adjL[node].begin();
        for(it=adjL[node].begin();it!=adjL[node].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it]=1;
                q.push(*it);
            }
        }
    }
    cout<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adjM(n+1,vector<int> (n+1,0));
    AdjList(n,m);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        BFS(n,m);
    }
    return 0;
}

