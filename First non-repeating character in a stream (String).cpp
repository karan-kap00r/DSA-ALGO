//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    // Code here
 	    unordered_map< char , int > m ;
		 deque< char > dq  ;
		 string ans ;
		  for(int i = 0 ; i < str.size() ; i++)
		  {
		      char a = str[i] ;
		      if(m[a] < 1)
		      {
		         dq.push_back(a) ;
		      }
		      m[a]++;
		      
		      while(m[dq.front()] != 1 && dq.size() >0 ) dq.pop_front() ;
		      
           if(dq.size() == 0) ans.push_back('#') ;
           else ans.push_back(dq.front()) ;
          }
		  return ans ;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
