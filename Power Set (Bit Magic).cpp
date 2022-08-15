//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> v;
		    int n=s.length();
		    for(int num=0;num<=(1<<n)-1;num++)
		    {
		        string str;
		        for(int bit=0;bit<=n-1;bit++)
		        {
		            if(num & (1<<bit))
		                str.push_back(s[bit]);
		        }
		      v.push_back(str);
		    }
		    sort(v.begin(),v.end());
		    v.erase(v.begin());
		  return v;
		}
		
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
