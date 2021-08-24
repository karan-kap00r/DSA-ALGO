#include<bits/stdc++.h>
using namespace std;

bool BalancedParenthesis(string s)
{
	int n=s.length();
	stack<char>st;
	bool ans=true;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')
		{
			st.push(s[i]);
		}
		else if((s[i]==')') && (!st.empty()))
		{
			if(st.top()=='(')
			{
				st.pop();
			}
			else
			{
				ans = false;
				break;
			}
		}
		else if((s[i]=='}') && (!st.empty()))
		{
			if(st.top()=='{')
			{
				st.pop();
			}
			else
			{
				ans = false;
				break;
			}
		}
		else if((s[i]==']') && (!st.empty()))
		{
			if(st.top()=='[')
			{
				st.pop();
			}
			else
			{
				ans = false;
				break;
			}
		}
	}
	if(!st.empty())
	return false;
	else
	return ans;
}

int main()
{
//	int x;
//	cout<<"Enter the no. of Test Cases : "<<endl;
//	cin>>x;
//	while(x--)
//	{
	string s="{[()}]";
	if(BalancedParenthesis(s))
	cout<<endl<<"VALID STRING"<<endl;
	else
	cout<<endl<<"INVALID STRING"<<endl;
//	}
	return 0;
}
