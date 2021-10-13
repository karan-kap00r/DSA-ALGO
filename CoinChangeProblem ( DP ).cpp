// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+2;
long long int dp[N][N];

 // } Driver Code Ends
class Solution {
  public:
//    long long int CoinChange(int s[], int m, int n) {		// By Tabulation Method

        // code here.
//        vector<long long int>dp(n+1,0);
//        dp[0]=1;
        // dp[1]=1;
//        for(int i=0;i<m;i++)
//        {
//            for(int j=0;j<n+1;j++)
//            {
//                if(j-s[i]>=0)
//                {
//                    dp[j]+=dp[j-s[i]];
//                }
//            }
//        }
//        return dp[n];
//    }
    
    long long int CoinChange(int s[],int m,int n)				// By Memorization Method
    {
    	if(n==0)
    		return 1;
    	if(n<0)
    		return 0;
    	if(m<=0 && n>0)
    		return 0;
    	if(dp[m][n]!=-1)
    		return dp[m][n];
    	dp[m][n]=CoinChange(s,m,n-s[m-1])+CoinChange(s,m-1,n);
    	return dp[m][n];
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.CoinChange(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
