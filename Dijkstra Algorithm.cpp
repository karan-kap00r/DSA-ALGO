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
        adjL[y].push_back({x,w});
    }
    
}


void Dijkstra(int src,int n)
{
    set<pair<int,int> > pq;
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    pq.insert({0,src});

    while(!pq.empty())
    {
        auto x=*(pq.begin());
        pq.erase(x);

        for(auto it: adjL[x.second])
        {
            if(dist[it.first] > dist[x.second]+it.second)
            {
                if(dist[it.first]!=INT_MAX)
                    pq.erase(pq.find({dist[it.first],it.first}));
                dist[it.first] = dist[x.second]+it.second;
                pq.insert({dist[it.first],it.first});
            }
        }
    }
    cout<<"distance from "<<src<<" are :"<<endl;
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
   
    vector<int> vis(n,0),din(n+1,INT_MAX);
    AdjList(n,m); 
    Dijkstra(1,n);
    return 0;
}

