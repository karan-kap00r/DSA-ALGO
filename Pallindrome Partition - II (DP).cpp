//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPallindrome(int i,int j,string s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }

    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            int minCost=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(isPallindrome(i,j,str))
                {
                    int Cost=1+dp[j+1];
                    minCost=min(minCost,Cost);
                }
            }
            dp[i]=minCost;
        }
        return dp[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
