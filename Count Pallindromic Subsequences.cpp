//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    long MOD = 1e9+7;
    public:
    /*You are required to complete below method */
 long countPS(string s){
     
  int len = s.length();
vector<vector<long>> dp(len,vector<long> (len,0));
  long ans = 0;
  for(int i = len - 1; i >= 0; --i){
      dp[i][i] = 1;
      for(int j = i + 1; j < len; ++j){
           if(s[i] == s[j]){
              dp[i][j] = ((dp[i+1][j] + dp[i][j-1]) % MOD + 1) % MOD; 
          }else{
              dp[i][j] = (dp[i][j-1] + dp[i + 1][j]- dp[i + 1][j-1] + MOD) % MOD;
          }
      }
  }
  
  return dp[0][len-1];
}
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends
