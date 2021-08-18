#include<bits/stdc++.h>
using namespace std;

int LongestSubstring(string s)
{
	int maxlen=0;
	int start=-1;
	vector<int>dict(256,-1);
	for(int i=0;i<s.length();i++)
	{
		if(dict[s[i]] > start)
		{
			start=dict[s[i]];
		}
		dict[s[i]]=i;
		
		maxlen=max(maxlen,i-start);
	}
	return maxlen;
}
int main()
{
	string s="pwwkew";
	cout<<LongestSubstring(s)<<endl;
	return 0;
}
