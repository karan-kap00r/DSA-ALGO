#include<bits/stdc++.h>
using namespace std;

void Reverse(int s[],int n)
{
	stack<int> st;
	int ans[n];
	for(int i=0;i<n;i++)
	{
		st.push(s[i]);
	}
	for(int j=0;j<n;j++)
	{
		ans[j]=st.top();
		st.pop();
	}
	for(int k=0;k<n;k++)
	{
		cout<<ans[k]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n,x;
	cout<<"enter the size of an array";
	cin>>n;
	int in[n];
	cout<<"enter the elements of the array";
	for(int j=0;j<n;j++)
	{
		cin>>x;
		in[j]=x;
	}
	cout<<"before reversing the Array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<in[i]<<" ";
	}
	cout<<endl<<"after reversing the array"<<endl;
	Reverse(in,n);
	cout<<endl;
	return(0);
}
