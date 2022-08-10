//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        int m=Matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++)
            dp[0][i]=Matrix[0][i];
            
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int u=Matrix[i][j] + dp[i-1][j];
                
                int ld=Matrix[i][j];
                if(j-1>=0)
                    ld+=dp[i-1][j-1];
                else
                    ld+= -1e9;
                
                int rd=Matrix[i][j];
                if(j+1<m)
                    rd+=dp[i-1][j+1];
                else
                    rd+= -1e9;
                    
                dp[i][j]=max(u,max(ld,rd));
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
