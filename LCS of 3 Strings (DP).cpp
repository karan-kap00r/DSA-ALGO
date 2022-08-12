//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}

// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>> (n2+1,vector<int> (n3+1,0)));
    for(int i=0;i<=n1;i++)  dp[i][0][0]=0;
    for(int i=0;i<=n2;i++)  dp[0][i][0]=0;
    for(int i=0;i<=n3;i++)  dp[0][0][i]=0;
    
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            for(int k=1;k<=n3;k++)
            {
                if(A[i-1]==B[j-1] && A[i-1]==C[k-1])
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
            }
        }
    }
    return dp[n1][n2][n3];
}
