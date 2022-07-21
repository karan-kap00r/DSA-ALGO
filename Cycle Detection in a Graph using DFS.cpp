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

bool DFS(int node,int prev)					//DFS TRAVERSAL
{
    vis[node]=true;
    // cout<<node<<" ";
    vector<int> :: iterator it;
    for(it=adjL[node].begin();it!=adjL[node].end();it++)
    {
        if(!vis[*it])
        {
            if(DFS(*it,node))
                return true;
        }
        else if(*it != prev)
            return true;
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adjM(n+1,vector<int> (n+1,0));
    AdjList(n,m);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        if(DFS(i,-1))
        {
            cout<<"Yes, there is a cycle"<<endl;
            break;
            // return true;
        }   
    }
    return false;
}

