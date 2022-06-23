// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


long long int MOD=1e9+7;
long long int N=1e5+2;
vector<int> dp(N,-1);
class Solution{
	public:
	
	long long fibbo(int n)
	{
	    if(n==0)
	        return 1;
	    
	    if(n==1)
	    {
	        return 2;
	    }
	    if(dp[n]!=-1)
	    {
	        return dp[n]%MOD;
	    }
	    
	        dp[n]=((fibbo(n-1)%MOD)+(fibbo(n-2)%MOD));
	    
	    return dp[n]%MOD;
	    
	}
	
	int TotalWays(int n)
	{
	    // Code here
	    
	    long long fib=fibbo(n);    
	    int ans=((fib%MOD)*(fib%MOD))%MOD;
	    return ans%MOD;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
