#include<bits/stdc++.h>
using namespace std;

int Multiply(int x,int res[],int res_size)
{
	// Initialize carry
	int carry=0;
 
    // One by one multiply x with individual digits of res[]
	for(int i=0;i<res_size;i++)
	{
		int prod=res[i]*x + carry;
		
		// Store last digit of 'prod' in res[] 
		res[i]=prod%10;
		
		// Put rest in carry
		carry=prod/10;
		
	}
	
	 // Put carry in res and increase result size
	while(carry)
	{
		res[res_size]=carry%10;
		carry=carry/10;
		res_size++;
	}
	return res_size;
}

void Factorial(int n)
{
	int res[500];
	int res_size=1;
	res[0]=1;
	
	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
	for(int x=2;x<=n;x++)
	{
		res_size=Multiply(x,res,res_size);
	}
	
	//Print OUTPUT
	cout << "Factorial of given number is "<<endl;
	for(int i=res_size-1;i>=0;i--)
	{
		cout<<res[i];
	}
}

int main()
{
	int num;
	cout<<"Enter the value whose factorial you want to find : "<<endl;
	cin>>num;
	Factorial(num);
	return 0;
}
