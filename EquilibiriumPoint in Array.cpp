// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long Lr[n],Rl[n];
        long long sum1=a[0];
        Lr[0]=sum1;
        for(int i=1;i<n;i++)
        {
            sum1+=a[i];
            Lr[i]=sum1;
        }
        long long sum2=a[n-1];
        Rl[n-1]=sum2;
        for(int i=n-1;i>=0;i--)
        {
            sum2+=a[i-1];
            Rl[i-1]=sum2;
        }
        
        for(int i=0;i<n;i++)
        {
            if(Rl[i]==Lr[i])
            {
                return i+1;
            }
        }
        // // for(auto i:Rl)
        // // cout<<i<<" ";
        // cout<<endl;
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
