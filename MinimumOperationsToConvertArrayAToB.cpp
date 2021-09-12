#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // Function to get length of the Longest Increasing Subsequence
    // in NlogN time.
	int LIS(vector<int>&a)		//Longest Increasing Subsequence Using DP(Tabulation)
	{
		int n=a.size();
		vector<int>DP(n,1);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[i]>a[j])
					DP[i]=max(DP[i],1+DP[j]);
			}
			ans=max(ans,DP[i]);
		}
		return ans;
	}

    int minInsAndDel(int A[], int B[], int N, int M) {
        
        map<int,int> mp;
        for(int i=0; i<M; i++)
            mp.insert({B[i],i});

        vector<int> res;

        for(int i=0; i<N; i++)
        {
            if(mp.find(A[i])!=mp.end())
                res.push_back(mp[A[i]]);
        }

        int ans = (N-LIS(res)) + (M-LIS(res));

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
