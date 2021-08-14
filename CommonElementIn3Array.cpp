#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int CommonElement(int a[],int b[],int c[],int n1,int n2,int n3)
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2 && k<n3)
	{
		if(a[i]==b[j] && b[j]==c[k])
		{
			cout<<" "<<a[i]<<"is a common element is matrix";
			i++;
			j++;
			k++;
		}
		else if(a[i]<b[j])
		i++;
		else if(b[j]<c[k])
		j++;
		else
		k++;
		int m=a[i-1];
		if(a[i]==m)
		i++;
		int n=b[j-1];
		if(b[j]==n)
		j++;
		int p=c[k-1];
		if(c[k]==p)
		k++;
	//	return i;
	}
	return -1;
}
void Display(int a[],int size)
{
	for (int d=0;d<size;d++)
	{
		
			cout<<" "<<a[d];
	}cout<<endl;
}
int main()
{
	int n;
	cout<<"enter the size of array";
	cin>>n;
	int k[n],l[n],h[n];
	for(int x=0;x<n;x++)
	cin>>k[x];

	cout<<endl;
	for(int y=0;y<n;y++)
	cin>>l[y];

	cout<<endl;
	for(int z=0;z<n;z++)
	cin>>h[z];
	sort(k,k+n);
	sort(l,l+n);
	sort(h,h+n);
    cout<<endl;
	Display(k,n);
	cout<<endl;
	Display(l,n);
	cout<<endl;
	Display(h,n);
	CommonElement(k,l,h,n,n,n);
	return 0;
 } 
