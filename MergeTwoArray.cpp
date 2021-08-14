#include<stdio.h>
#include<iostream>
using namespace std;
void MergeTwoArray(int a[],int b[],int m,int n)
{
	
	for(int i=n-1;i>=0;i--)
	{
		int j;
		int last=a[m-1];
		for(j=m-2 ; j>=0 && a[j]>b[i] ; j--)
		a[j+1]=a[j];
			if (j!=m-2 || last>b[i])
			{
				a[j+1]=b[i];
				b[i]=last;
			}
		
	}
}


void display(int a[],int size)
{
	for(int i=0;i<=size-1;i++)
	cout<<"  "<<a[i];
}
int main()
{
	int a[6]={1,5,9,10,15,20};
	int b[4]={2,3,8,13};
	MergeTwoArray(a,b,6,4);
	display(a,6);
//	cout<<endl;
	display(b,4);
	return(0);
}

