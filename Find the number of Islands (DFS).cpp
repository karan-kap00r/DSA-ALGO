//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int a[3]={0,1,-1};

class Solution {
  public:
  void dfs(vector<vector<char>>&g,int m,int n,bool vis[1000][1000])
   {
       if(vis[m][n]==true || m<0|| m>=g.size()|| n<0 || n>=g[0].size()||g[m][n]=='0')
       {
           return;
       }
       
       vis[m][n]=true;
       for(int x: a)
       {
           for(int y : a)
           {
               
               dfs(g,m+x,n+y,vis);
           }
       }
   }    
       
  int numIslands(vector<vector<char>>& g) {
  bool vis[1000][1000];
  
  for(int i=0;i<g.size();i++)
   {
       for(int j=0;j<g[0].size();j++)
       {
           vis[i][j]=false;
       }
   }
  int count=0;
   for(int i=0;i<g.size();i++)
   {
       
       for(int j=0;j<g[0].size();j++)
       {
           
           if(g[i][j]=='1' && vis[i][j]==false)
           {
               dfs(g,i,j,vis);
               count++;
           }
       }
   }
  return count;
    
   }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
