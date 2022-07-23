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
    
}

void BFS(int n,vector<int> &din)
{
    queue<int> q;
    vector<int> ans;
    din[n]=0;
    q.push(n);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto i:adjL[node])
        {
            if(din[node]+1<din[i])
            {
                din[i]=din[node]+1;
                q.push(i);
            }
        }
    }
    return ;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
   
    vector<int> vis(n,0),din(n,INT_MAX);
    AdjList(n,m);  
    BFS(0,din);
    for(auto i:din)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

