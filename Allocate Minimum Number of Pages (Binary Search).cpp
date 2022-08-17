//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
bool isPossible (int a[], int n, int m, int mid)
    {
        int pageSum = 0;
        int studentCount = 1;
        
        for (int i = 0; i < n; i++)
        {
            if (pageSum + a[i] <= mid)
                pageSum += a[i];
            else
            {
                studentCount++;
                if (studentCount > m || a[i] > mid)
                    return false;
                //not possible to allocate books
                pageSum = a[i];
            }
        }//all books allocated
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        int sum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
            sum += a[i];
            
        int start = 0;
        int end = sum;
        //search space extremes
        
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (isPossible(a,n,m,mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            start = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
