//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(vector<vector<int>> arr, int M, int N) 
	{ 
	    // Your code goes here
	    vector<vector<int>> hp(M+1,vector<int> (N+1,INT_MAX));
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
        
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) 
            {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - arr[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(a, m, n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
