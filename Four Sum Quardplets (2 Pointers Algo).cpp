//	GOOGLE INTERVIEW PROBLEM !!
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> res;
        int n=arr.size();
        if(n==0)
            return res;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int tar=k-arr[i]-arr[j];
                int front=j+1,back=n-1;
                while(front<back)
                {
                    int two_sum=arr[front]+arr[back];
                    if(two_sum < tar)
                        front++;
                    else if(two_sum>tar)
                        back--;
                    else
                    {
                        vector<int> tmp(4,0);
                        tmp[0]=arr[i];
                        tmp[1]=arr[j];
                        tmp[2]=arr[front];
                        tmp[3]=arr[back];
                        res.push_back(tmp);
                        
                        while(front<back && arr[front]==tmp[2])
                            front++;
                        while(front<back && arr[back]==tmp[3])
                            back--;
                    }
                }
                while(j+1<n && arr[j+1]==arr[j])
                    j++;
            }
            while(i+1<n && arr[i+1]==arr[i])
                i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
