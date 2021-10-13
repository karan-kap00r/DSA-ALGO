#include<bits/stdc++.h>
using namespace std;

int dp[1000];

int friendsPairing(int n)
{
	
	if(dp[n]!=-1)
		return dp[n];
	if(n>2)
		return dp[n]=friendsPairing(n-1)+((n-1)*friendsPairing(n-2));
	else
		return dp[n]=n;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	cout<<"Enter the value of N"<<endl;
	cin>>n;
	cout<<friendsPairing(n)<<endl;
	return 0;
}
