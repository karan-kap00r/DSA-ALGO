#include<stdio.h>
#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void display(int arr[],int size)
{
	for(int i=0;i<=size-1;i++)
	cout<<"  "<<arr[i];
}
void SORT(int arr[],int size)
{
	int low=0;
	int high=size-1;
	int mid=0;
while (mid <= high) { 
        switch (arr[mid]) { 
  
        // If the element is 0 
        case 0: 
            swap(arr[low++], arr[mid++]); 
            break; 
  
        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 
  
        // If the element is 2 
        case 2: 
            swap(arr[mid], arr[high--]); 
            break; 
        } 
}
}

int main()
{
	int size;
	cout<<"enter the size of an array"<<endl;
	cin>>size;
	int arr[size];
	cout<<"enter the elements of an array"<<endl;
	for(int l=0;l<=size-1;l++)
	{
		cin>>arr[l];
	}
	cout<<"before sorting"<<endl;
	display(arr,size);
	SORT(arr,size);
	cout<<endl<<"after sorting"<<endl;
	display(arr,size);
	return(0);
}
