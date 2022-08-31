//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string ans="";
        stack<char> st;
        for(int i=0;i<=s.length();i++)
        {
            if(i==s.size() or s[i]=='.')
            {
                while(!st.empty())
                {
                char ch=st.top();
                st.pop();
                ans.push_back(ch);
                }
                ans.push_back('.');
            }
            else
            {
                st.push(s[i]);
            }
        }
        ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
