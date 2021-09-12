#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
const int N=1e5+2;
    long long smallestpositive(vector<long long> array, int n)
    { 
        // code here
        long long res=1;
        sort(array.begin(),array.end());
  		for (int i = 0; i < n && array[i] <= res; i++)
       		res = res + array[i];
 
   return res;
    } 
};


// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends
