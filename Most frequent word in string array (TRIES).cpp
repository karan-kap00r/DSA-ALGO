//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    struct TrieNode {
        TrieNode *child[26];
        int count ;
        int index ;
        int first;
        TrieNode()
        {
            count = 0;
            index = -1;
            first = -1;
            for(int i=0;i<26;i++)
                child[i] = NULL ;
        }
    };
    
    int maxCount = 0 , maxIndex = 0 , maxFirst = 0;
    void insert(TrieNode *root , string key , int i)
    {
        TrieNode *curr = root;
        for(int i=0;i<key.size();i++)
        {
            int index = key[i] - 'a';
            if(curr ->child[index] == NULL)
                curr ->child[index] = new TrieNode ();
                
            curr = curr ->child[index];
        }
        if(curr -> count == 0)
            curr -> first = i;
        
        curr -> count += 1;
        if(curr -> count > maxCount)
        {
            maxCount = curr->count;
            maxIndex = i;
            maxFirst = curr -> first;
        }
        else if(curr -> count == maxCount)
        {
            maxCount = curr->count;
            maxFirst = max(maxFirst , curr->first);
        }
        
    }
    
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        TrieNode *root = new TrieNode();
        for(int i=0;i<n;i++)
        {
            insert(root,arr[i],i);
        }
        //cout<<maxCount;
        return arr[maxFirst];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
