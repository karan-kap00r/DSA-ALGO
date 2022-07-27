//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ipi pair<int,pair<int,int> > 
 vector<int> dx{1,-1,0,0};
 vector<int> dy{0,0,-1,1};
 
class Solution
{
    public:
    int ans=INT_MAX;
    bool isValid(int i, int j, int n) {
        return i>=0&&j>=0&&i<n&&j<n;
    }
    
   
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        vector<vector<int> > dp(n, vector<int> (n, INT_MAX));
        priority_queue<ipi, vector<ipi> , greater<> > pq;
        pq.push({grid[0][0],{0,0}});
        dp[0][0]=grid[0][0];
        while(!pq.empty()) {
            int i=pq.top().second.first, j=pq.top().second.second;
            pq.pop();
            if(i==n-1&&j==n-1) break;
            for(int k=0; k<4; k++) {
                int x=i+dx[k], y=j+dy[k];
                if(isValid(x,y,n)&&dp[x][y]>=dp[i][j]+grid[x][y]) {
                    dp[x][y]=dp[i][j]+grid[x][y];
                    pq.push({dp[x][y],{x,y}});
                }
            }
        }
        return dp[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
