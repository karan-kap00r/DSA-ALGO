
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dis(int arr[],int n,int k)
    {
        unordered_map<int,int> m;
        int cnt=0,i=0;
        for(int j=0;j<n;j++)
        {
         m[arr[j]]++;
         while(i<=j && m.size()>=k)
         {
            cnt+=n-j;
            m[arr[i]]--;
            if(m[arr[i]]==0)
                m.erase(arr[i]);
            i++;
         }
        }
        return cnt;
    }
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
       
        int cnt=0;
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }
        int k=s.size();
        cnt=dis(arr,n,k);
        return cnt;
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
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
