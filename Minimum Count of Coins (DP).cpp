//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
int minCoins(int coins[], int M, int V) 
{ 
  vector<vector<int>> dp(M+1, vector<int> (V+2, -1));  
   for(int i=1; i<=V; i++){
       if(i%coins[0]==0)  dp[0][i]= i/coins[0];
       
         else dp[0][i]=1000000;
    } 
       for(int i=0; i<M; i++){
     dp[i][0]=0;
    }


    for(int i=1; i<M; i++){
        for(int j=0; j<=V; j++){
            int ans=1000000;
           if(j-coins[i]>=0){
               ans=min(ans, 1+dp[i][j-coins[i]]);
           }
            ans=min(ans, dp[i-1][j]);
            dp[i][j]=ans;
        }
    }

 

     int a=dp[M-1][V];
     if(a>=1000000) return -1;
     
     return a;
   


}   
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
