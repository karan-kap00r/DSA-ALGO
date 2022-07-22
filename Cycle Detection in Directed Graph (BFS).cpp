//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {

      vector<int> indeg(V,0);
      for(int i=0;i<V;i++)
      {
          for(auto it:adj[i])
          {
              indeg[it]++;
          }
      }
      queue<int> q;
      for(int i=0;i<V;i++)
      {
          if(!indeg[i])
          {
              q.push(i);
          }
      }
      int cnt=0;
      while(!q.empty())
      {
          int curr = q.front();
          cnt++;
          q.pop();
          
          for(auto it: adj[curr])
          {
              indeg[it]--;
              if(!indeg[it])
              {
                  q.push(it);
              }
          }
      }
      if(cnt < V) 
      return true;
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
