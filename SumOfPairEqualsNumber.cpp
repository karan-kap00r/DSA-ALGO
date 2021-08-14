#include<bits/stdc++.h>
using namespace std;
int main()
{
	array<int,5>a1={2,3,0,1,6};
	int i,j,SUM,temp=0;
	cout<<"ARRAY IS :"<<endl;
	for(int i:a1)
	cout<<i<<" ";
	
	cout<<endl<<"Enter the value of SUM"<<endl;
	cin>>SUM;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if((a1[i]+a1[j]==SUM)&&(i!=j))
			{
				temp=1;
				cout<<"sum of "<<a1[i]<<"and "<<a1[j]<<" is equals to "<<SUM <<endl;
			}
		}
	}
	if(temp==0)
	cout<<" There is no pair of numbers whose sum equals to "<<SUM<<endl;
	return 0;
}
