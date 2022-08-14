// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    
    void solve(int a[],int n,int k,int currsum,int count,vector<int>&visited,int sum,bool&ans)
    {
        if(count==k-1)
            {
                ans=true;
                return;
            }
            
        if(currsum>sum)
            return;
            
        if(currsum==sum)
            { return solve(a,n,k,0,count+1,visited,sum,ans);
              if(ans==true)
                    return;
            }
            
        for(int i=0;i<n;++i)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                solve(a,n,k,currsum+a[i],count,visited,sum,ans);
                if(ans==true)
                    return; 				// Return if you got (sum==target) from a subset
                visited[i]=false;			//BACKTRACKING
            }
        }
        
        return;
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if(k>n)
            return false;
            
        if(k==1)
            return true;
            
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=a[i];
        }
        
        if(sum%k!=0)
            return false;
            
        vector<int> visited(n,false);
        bool ans=false;
        solve(a,n,k,0,0,visited,sum/k,ans);    		//Target =(Sum/K)
        return ans;
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends
