 #include<bits/stdc++.h>

using namespace std; 
 
// 1st METHOD
int RainWater(vector<int> a)
{
	int n=a.size();
	int ans=0;
	stack<int>st;
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && a[st.top()]<a[i])
		{
			int curr=st.top();
			st.pop();
			if(st.empty())
			{
				break;
			}
		int diff=i-st.top()-1;
		ans+=(min(a[st.top()],a[i])-a[curr])*diff;
		}
		st.push(i);
	}	
	return ans;
}

int main()
{
	int n;
	cout<<"Enter the size of the vector : "<<endl;
	cin>>n;
	vector<int> a(n);
	cout<<"Enter the values of the vector: "<<endl;
	for(auto &i:a)
		cin>>i;
	int x=RainWater(a);
	cout<<"The amount of rainwater trapped is : "<<endl<<x<<endl;
	return 0;
}
 
 
// 2nd METHOD
// int RainWater(int arr[],int n)
// {
// 	int result = 0;
// 
//    // maximum element on left and right
//    int left_max = 0, right_max = 0;
// 
//    // indices to traverse the array
//    int lo = 0, hi = n - 1;
// 
//    while (lo <= hi) {
//        if (arr[lo] < arr[hi]) {
//            if (arr[lo] > left_max)
//                // update max in left
//                left_max = arr[lo];
//            else
//                // water on curr element = max - curr
//                result += left_max - arr[lo];
//            lo++;
//        }
//        else {
//            if (arr[hi] > right_max)
//                // update right maximum
//                right_max = arr[hi];
//            else
//                result += right_max - arr[hi];
//            hi--;
//        }
//    }
// 
//    return result;
//}
//
//int main()
//{
//	int arr[12]={0,1,0,2,1,0,1,3,2,1,2,1};
//	int x=RainWater(arr,12);
//	cout<<x<<endl;
//	return 0;
//}
