// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int res,i,j;
        int dp[n+1][k+1]={{0}};
        for (i = 1; i <= n; i++) {
            dp[i][1] = 1;
            dp[i][0] = 0;
    }
    for (j = 1; j <= k; j++)
        dp[1][j] = j;
        
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=k;j++)
            {
                dp[i][j] = INT_MAX;
                for(int x=1;x<=j;x++)
                {
                res=  1 + max(dp[i-1][x-1], dp[i][j-x]);
                if(res<dp[i][j])
                    dp[i][j]=res;
                }
            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
