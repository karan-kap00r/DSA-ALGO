#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>>pqmax;					//global variables
priority_queue<int,vector<int>,greater<int>>pqmin;		//global variables

void insert(int x)
{
	if(pqmax.size()==pqmin.size())
	{
		if(pqmax.size()==0)
		{
			pqmax.push(x);
			return;
		}
		if(x < pqmax.top())
			pqmax.push(x);
		else
			pqmin.push(x);
		
	}
	else
	{
		if(pqmax.size() > pqmin.size())
		{
			if(x >= pqmax.top())
			{
				pqmin.push(x);
			}
			else
			{
				int temp=pqmax.top();
				pqmax.pop();
				pqmin.push(temp);
				pqmax.push(x);
			}
		}
		else
		{
				if(x <= pqmin.top())
			{
				pqmax.push(x);
			}
			else
			{
				int temp=pqmin.top();
				pqmin.pop();
				pqmax.push(temp);
				pqmin.push(x);
			}
		}
	}
}

double FindMedian()
{
	if(pqmin.size()==pqmax.size())
	{
		return ((pqmax.top()+pqmin.top())/2.0);
	}
	else if(pqmax.size() > pqmin.size())
		return pqmax.top();
	else
		return pqmin.top();
}

int main()
{
	int arr[6]={10,15,21,30,18,19};
	for(int i=0;i<6;i++)
	{
		insert(arr[i]);
		cout<<i<<" --Median : "<<FindMedian()<<endl;
	}
	return 0;
}
