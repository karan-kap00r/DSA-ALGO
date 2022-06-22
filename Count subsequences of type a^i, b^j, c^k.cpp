
#include<bits/stdc++.h>
using namespace std;


long long int MOD=1e9+7;
class Solution{
  public:
    int fun(string &s) {
        //code here
        long long int a=0,ab=0,abc=0;
        for(char ch: s)
        {
            if(ch=='a')
            {
                a=(2*a%MOD+1)%MOD;
            }
            if(ch=='b')
            {
                ab=(2*ab%MOD+a)%MOD;
            }
            if(ch=='c')
            {
                abc=(2*abc%MOD+ab)%MOD;
            }
        }
        return abc;
    }
};

 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  
