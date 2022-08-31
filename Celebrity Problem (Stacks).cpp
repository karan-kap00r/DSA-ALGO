//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    bool knows(int i,int j,vector<vector<int> >& a)
    {
        if(a[i][j]==1)
            return true;
        else
            return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++)
            s.push(i);
        
        while(s.size()!=1)
        {
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            
            if(knows(x,y,a))
                s.push(y);
            else
                s.push(x);
        }
        int rs=s.top();
        bool rowCheck=false;
        int rowcnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[rs][i]==0)
                rowcnt++;
        }
        
        bool colCheck=false;
        int colcnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][rs]==1)
                colcnt++;
        }
        
        if(rowcnt==n) 
            rowCheck=true;
        if(colcnt==n-1)
            colCheck=true;
            
        if(rowCheck && colCheck)
            return rs;
        else
            return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
