// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int dp[1001][1001];

class Solution{
	public:
	
	int test(int arr[],int n,int x,int y)
	{
	    if(x==y)
	        return arr[x];
	   if(x>y)
	        return 0;
	   if(dp[x][y]!=-1)
	        return dp[x][y];
	   int l=arr[x]+min(test(arr,n,x+2,y),test(arr,n,x+1,y-1));
	   int r=arr[y]+min(test(arr,n,x,y-2),test(arr,n,x+1,y-1));
	   return dp[x][y]=max(l,r);
	}
	
	int maxAmount(int arr[], int n)
	{
		
		// Your code goes here
        memset(dp,-1,sizeof(dp));
        int x=test(arr,n,0,n-1);
        return x;
	}
};

// { Driver Code Starts.
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
	    cout << ob.maxAmount(a, n) << "\n";

	     
    }
    return 0;
}
  // } Driver Code Ends
