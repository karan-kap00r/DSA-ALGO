//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool helper(int node,vector<int>&vis,vector<int> adjL[])
  {
      if(vis[node]==2)
        return true;
      vis[node]=2;

      for(auto i:adjL[node])
      {
          if(vis[i]==1)
          {
             continue;
          }
          
          if(helper(i,vis,adjL)==true)
            return true;
      }
      vis[node]=1;
      return false;
  }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adjL[]) {
        // code here
         vector<int> vis(n,0),dfsvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0){
            if(helper(i,vis,adjL))
            {
                // cout<<"It has a cycle"<<endl;
                 return true;
            }   
          }
        }
        // cout<<"It doesn't have a cycle"<<endl;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
