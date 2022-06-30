// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int N){
        // code here
        long long int m=4;
        vector<long long int> dp(N+1);
        
        for(int i=1;i<=N;i++)
        {
            if(i<m)
                dp[i]=1;
            else if(i==m)
                dp[i]=2;
            else
            {
                dp[i]=dp[i-1]+dp[i-m];
            }
        }
        return dp[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
