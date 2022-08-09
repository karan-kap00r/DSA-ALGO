//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
int minDifference(int nums[], int n)  {
	    
	   int totalSum=0;
	   
        for(int i=0;i<n;i++)
        {
            totalSum+=nums[i];
        }
        int target=totalSum;
        
        vector<vector<bool>>dp(n,vector<bool>(target+1,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=target) dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                bool nontake=dp[i-1][j];
                
                bool take=false;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];
                
                dp[i][j]=(take or nontake);
            }
        }
        
        int mini=1e9;
        for(int i=0;i<=target/2;i++)
        {
            if(dp[n-1][i]==true)
            {
                int s1=i;
                int s2=target-i;
                mini=min(mini,abs(s1-s2));
            }
        }
        return mini;
        
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
