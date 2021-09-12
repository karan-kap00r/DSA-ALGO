// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
	string printMinIndexChar(string S, string patt)
	{
	    // Code here
	    map<char,int>mp;
	    for(int i=0;i<patt.length();i++)
	    {
	        mp[patt[i]]++;
	    }
	    map<char,int>::iterator it;
	    int ans=INT_MAX;
	    for(int i=0;i<S.length();i++)
	    {
	        it=mp.find(S[i]);
	        if(it != mp.end() )
	        {
	            ans=min(ans,i);
	        }
	    }
	    string res="";
	    if(ans!=INT_MAX)
	        res=res + S[ans];
	   else
	        res=res + '$';
	   return res;
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cout<<"Enter the number of test cases"<<endl;
    cin>>t;
    
    cout<<"Enter the test strings"<<endl;
    while(t--)
    {
        string str;
        cin>>str;
        string patt;
        cin >> patt;
        Solution obj;
        cout<<obj.printMinIndexChar(str, patt)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends=
