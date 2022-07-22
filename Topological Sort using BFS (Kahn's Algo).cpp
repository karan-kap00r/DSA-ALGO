

//KAHN'S ALGORITHM

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
    
}

vector<int> BFS(int n,vector<int> &din)
{
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(din[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto i:adjL[node])
        {
            din[i]--;
            if(din[i]==0)
                q.push(i);
        }
    }
    return ans;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
   
    vector<int> vis(n,0),din(n,0),ans;
    // unordered_map<int,int> ind;
    AdjList(n,m);

    for(int i=0;i<n;i++)
    {
        for(auto it:adjL[i])
            din[it]++;
    }
    ans=BFS(n,din);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

