//CATALAN NUMBER :- submisison of (Ci.Cn-i)     ,where i=0 to n-1

#include<bits/stdc++.h>
using namespace std;

int Catalan(int n)
{
	if(n<=1)
		return 1;
	int res=0;
	for(int i=0;i<=n-1;i++)
	{
		res+=Catalan(i)*Catalan(n-i-1);
	}
	return res;
}

int main()
{
	int n;
	cout<<"Enter the value of N "<<endl;
	cin>>n;
	cout<<"Catalan Numbers upto N is : "<<endl;
	for(int i=0;i<=n;i++)
		cout<<Catalan(i)<<" ";
	cout<<endl;
	return 0;
}
