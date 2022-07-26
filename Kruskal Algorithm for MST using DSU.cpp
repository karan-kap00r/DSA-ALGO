#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2,MOD=1e9+7;

// vector<int> rank[1e5,0],parent[1e5];

// Steps for KRUSKAL ALGO   -   T.C: O(M log M)

// 1. Sort all edges w.r.t weights  (wt,u,v)
// 2. Greedly Pick up the shortest edge
// 3. Check whether the two vertcies of that edge belongs to same component using DSU->to avoid cycle in Minimum Spanning Tree:
        //  (if not join them)
        //  (else do not pick them)
// 4. Repeat 2


struct node{
    int u;
    int v;
    int wt;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};

bool comp(node a,node b)
{
    return a.wt<b.wt;
}

void makeSet(int n,vector<int> parent,vector<int> rank)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int findPar(int node,vector<int> &parent)
{
    if(node==parent[node])
        return node;

    return findPar(parent[node],parent);      //Path Compression
}

void Union(int u, int v,vector<int> &parent,vector<int> &rank)
{
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[v]<rank[u])
        parent[v]=u;
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}

void Kruskal(int n,vector<node> edges,vector<int> parent,vector<int> rank)
{
    int cost=0;
    for(auto it: edges)
    {
        if(findPar(it.v,parent) != findPar(it.u,parent))
        {
            cost+=it.wt;
            cout<<it.u<<" - "<<it.v<<endl;
            Union(it.u,it.v,parent,rank);
        }
    }
    
    cout<<"cost is : "<<cost<<endl;
}


int main()
{
    int n,m;
    cin>>n>>m;
   vector<node> edges;
   for(int i=0;i<m;i++)
   {
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back(node(u,v,wt));
   }
   sort(edges.begin(),edges.end(),comp);

    vector<int> rank(n+1,0),parent(n+1);

    for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    Kruskal(n,edges,parent,rank);
    return 0;
}

