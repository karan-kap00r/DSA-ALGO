//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char s[], int N)
{
    //code here
    vector<vector<int>> dp(N,vector<int>(N));
    int count=0;
    for(int i=N-1;i>=0;i--){
        for(int j=i;j<N;j++){
            if(j==i){
                dp[i][j]=1;
            }
            else if(j-i==1) { 
                dp[i][j]= s[i]==s[j] ? 1 :0; //length 1
            }
            else{
                dp[i][j]= s[i]==s[j] ? dp[i+1][j-1] : 0; //length 2
            }
            if(j-i>=1)
                count+=dp[i][j];
        }
    }
    return count;
    
}
