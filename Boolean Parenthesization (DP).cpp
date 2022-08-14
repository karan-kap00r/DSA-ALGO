//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int mod=1003;

    int f(int i,int j,bool isTrue,string &s, vector<vector<vector<int>>> &dp)
    {
        
        if(i>j) return 0;                                       //BASE CASES
        if(i==j){
            if(isTrue) return s[i]=='T';
            if(!isTrue) return s[i]=='F';
        }
        
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];       //MEMOAIZATION
        
        int count=0;
        for(int k=i+1;k<j;k+=2){
            int lt=f(i,k-1,1,s,dp);
            int rt=f(k+1,j,1,s,dp);
            int lf=f(i,k-1,0,s,dp);
            int rf=f(k+1,j,0,s,dp);
            
            if(s[k]=='&'){                      //AND
                if(isTrue) count+=(lt*rt)%mod;
                if(!isTrue) count+=(lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod;
            }
            else if(s[k]=='^')                  //XOR
            {                
                if(isTrue) count+=(lt*rf+lf*rt)%mod;
                if(!isTrue) count+=(lt*rt+lf*rf)%mod;
            }
            else                                //OR
            {                              
                if(isTrue) count+=((lt*rf)%mod+(lf*rt)%mod+(lt*rt)%mod)%mod;
                if(!isTrue) count+=(lf*rf)%mod;
            }
        }
        return dp[i][j][isTrue]=(count)%mod;
    }
    
    int countWays(int n, string s)
    {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
