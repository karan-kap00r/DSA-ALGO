//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
       // code here
       vector<int>ans;
       vector<vector<int>>dp(R,vector<int>(C));
       dp[0][0]=M[0][0];
      for(int i=1;i<R;i++){
           dp[i][0]=dp[i-1][0]+M[i][0];
       }
       for(int j=1;j<C;j++){
           dp[0][j]=dp[0][j-1]+M[0][j];
       }
       for(int i=1;i<R;i++){
           for(int j=1;j<C;j++){
               dp[i][j]=M[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
           }
       }
       for(int q=0;q<Q;q++){
           int i=q_i[q];
           int j=q_j[q];
           int min_dist=min(min(i,j),min(R-1-i,C-1-j));
           int curr=0;
           int l=0;
           int h=min_dist;
           while(l<=h){
               int k=(l+h)/2;
               int x1=i-k;
               int y1=j-k;
               int x2=i+k;
               int y2=j+k;
               int count=dp[x2][y2];
               if(y1>0)count-=dp[x2][y1-1];
               if(x1>0)count-=dp[x1-1][y2];
               if(x1>0 && y1>0)count+=dp[x1-1][y1-1];
               
               if(count<=K){
                   curr=2*k+1;
                   l=k+1;
               }else{
                   h=k-1;
               }
           }
           ans.push_back(curr);
       }
       return ans;
   }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R,C,K,Q,x;
        cin>>R>>C;
        vector<vector<int>> M;
        
        for(int a=0; a<R; a++)
        {
            vector<int> temp;
            for(int b=0; b<C; b++)
            {
                cin>>x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }
        
        cin>>K>>Q;
        
        int q_i[Q], q_j[Q];
        
        for(int i=0; i<Q; i++)
            cin>>q_i[i];
        for(int i=0; i<Q; i++)
            cin>>q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M,R,C,K,Q,q_i,q_j);
        
        for(int i=0; i<Q; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
