//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
  int bit_cnt_b=__builtin_popcount(b);
  
        int bit_cnt_a=__builtin_popcount(a);
        
        if(bit_cnt_a==bit_cnt_b)return a;
        
        else if(bit_cnt_a>bit_cnt_b)
        {
            int diff=bit_cnt_a-bit_cnt_b;
            int i=0;
            
            while(diff)
            {
                int bit=a & (1<<i);
                if(bit>0)
                {
                    a=a-bit;
                    diff--;
                }
                i++;
            }
            return a; 
        }
        
        else if(bit_cnt_a<bit_cnt_b){
            int diff=bit_cnt_b-bit_cnt_a;
            int i=0;
          
            while(diff)
            {
                int bit=a& (1<<i);
               
                if(bit==0)
                {
                    a=a+(1<<i);
                    diff--;
                }
                i++;
            }
            return a;
    }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
