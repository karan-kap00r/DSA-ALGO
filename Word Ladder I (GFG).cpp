//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        int start_length=startWord.size();
        int target_length=targetWord.size();
        
        if(start_length!=target_length){
            return 0;
        }
        
        unordered_set<string>s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        
        if(s.find(targetWord)==s.end()){
            return 0;
        }
        
        queue<string>q;
        q.push(startWord);
        int ans=0;
        
        while(!q.empty()){
            
            ans++;
            int q_len=q.size();
           for(int i=0;i<q_len;i++){
            string present_word=q.front();
            q.pop();
          
            for(int j=0;j<start_length;j++){
              char a=present_word[j];
              
            for(char c='a';c<='z'; c++){
                 present_word[j]=c;
                 if(present_word==targetWord){
                     return ans+1;
                 }
                 if(s.find(present_word)==s.end()){
                     continue;
                 }
                 s.erase(present_word);
                 q.push(present_word);
                 
          }  
          present_word[j]=a;
        }      
    }
}
return 0;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
