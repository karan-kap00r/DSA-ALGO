//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
 int *findTwoElement(int *arr, int n) {
        // code here
        int *ans;
        int x=0;
        for(int i=0;i<n;i++) x^=arr[i];
        for(int i=1;i<=n;i++) x^=i;
        int rsbm=x&(-x);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if((arr[i]&rsbm)==0){
                a^=arr[i];
            }else{
                b^=arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if((i&rsbm)==0){
                a^=i;
            }else{
                b^=i;
            }
        }
        ans[0]=a,ans[1]=b;
        for(int i=0;i<n;i++){
            if(ans[0]==arr[i]) break;
            if(ans[1]==arr[i]){
                int temp=ans[0];
                ans[0]=ans[1];
                ans[1]=temp;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
