#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2,MOD=1e9+7;
vector<int> adjL[N];

void AdjMatrix( vector<vector<int> > &adjM,int n,int m)             //   GRAPH USING ADJACENCY MATRIX
{
for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adjM[x][y]=1;
        adjM[y][x]=1;

    }
    cout<<"adjacency Matrix is given by:"<<endl;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }
}

void AdjList(int n,int m)         //   GRAPH USING ADJACENCY LIST
{
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }
    cout<<"Adjacency List is given by:"<<endl;
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<" --> ";
        for(auto j:adjL[i])
            cout<<j<<" ";
        cout<<endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adjM(n+1,vector<int> (n+1,0));
    // AdjMatrix(adjM,n,m);
    AdjList(n,m);
    return 0;
}

