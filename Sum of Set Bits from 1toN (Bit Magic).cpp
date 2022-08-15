//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int fun(int n)                  // to find maximum power of 2 which is less than n
    {
        int x = 0;
        while((1<<x)<=n){
            x++;
        }
        return x-1;
    }
    
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        if(n==0) return 0;
        int x = fun(n);
        
        int s1 = (x*(1<<(x-1)));        //(2^x-1)*x
        int s2 = (n-(1<<x)+1);          //n-(2^x) + 1
        
        return s1+s2+countSetBits(n-(1<<x));
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
