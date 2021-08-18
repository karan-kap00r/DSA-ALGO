#include<bits/stdc++.h>
using namespace std;

vector<int> MergeKArrays(vector<vector<int>> arr,int k)
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;	//MinHeap declared
	for(int i=0;i<k;++i)		//pushed 1st array
	{
		q.push({arr[i][0],{i,0}});
	}
	vector<int> ans;		//answer vector 
	while(!q.empty())
	{
		int val=q.top().first;				//1st element of pair -> value
		int row=q.top().second.first;		//2nd element of pair -> row
		int index=q.top().second.second;	//3rd element of pair -> index
		
		q.pop();							//top minimum element poped
		ans.push_back(val);					// and pushed in answer vector
		if(index<k-1)						//check if the array is last array in the 'K' arrays or not
		{
			q.push({arr[row][index+1],{row,index+1}});	
		}
	}
	return ans;
}
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	vector<vector<int>> arr={{1,5,7},{3,5},{1,2,6}};
	vector<int> ans;
	ans=MergeKArrays(arr,3);	//K=3
	printArray(ans,8);
	cout<<endl;
	return 0;
}
