// A C++ program to print union and intersection
/// of two unsorted arrays
#include <algorithm>
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x);

// Prints union of arr1[0..m-1] and arr2[0..n-1]
void printUnion(int arr1[], int arr2[], int size)
{
	// Before finding union, make sure arr1[0..m-1]
	// is smaller
/*	if (m > n) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	// Now arr1[] is smaller

	// Sort the first array and print its elements (these
	// two steps can be swapped as order in output is not
	// important)
	sort(arr1, arr1 + m);*/
	for (int i = 0; i < size; i++)
		cout << arr1[i] << " ";

	// Search every element of bigger array in smaller array
	// and print the element if not found
	for (int i = 0; i < size; i++)
		if (binarySearch(arr1, 0, size - 1, arr2[i]) == -1)
			cout << arr2[i] << " ";
}

// Prints intersection of arr1[0..m-1] and arr2[0..n-1]
void printIntersection(int arr1[], int arr2[], int size)
{
	// Before finding intersection, make sure arr1[0..m-1]
	// is smaller
	/*if (m > n) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	// Now arr1[] is smaller

	// Sort smaller array arr1[0..m-1]
	sort(arr1, arr1 + m);

	// Search every element of bigger array in smaller
	// array and print the element if found*/
	for (int i = 0; i < size; i++)
		if (binarySearch(arr1, 0, size - 1, arr2[i]) != -1)
			cout << arr2[i] << " ";
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then it can only
		// be presen in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right
		// subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}

void display(int arr[],int size)
{
	for(int i=0;i<size;i++)
	cout<<"  "<<arr[i]<<endl;
}
/* Driver program to test above function */
int main()
{
	
		int n;
	cout<<endl<<"enter the value of n";
	cin>>n;
	int arr1[n],arr2[n];
	cout<<endl<<" enter the values for array a";
	for(int k=0;k<=n-1;k++)
	{
		cin>>arr1[k];
	}
	cout<<"enter the valures for array b";
	for(int l=0;l<=n-1;l++)
	{
		cin>>arr2[l];
	}
		cout<<"sorted version of array a";
	sort(arr1,arr1+n);
	display(arr1,n);
	cout<<"sorted version of array b";
	sort(arr2,arr2+n);
	display(arr2,n);

	// Function call
	cout << "Union of two arrays is ";
	printUnion(arr1, arr2, n);
	cout << endl<<"Intersection of two arrays is ";
	printIntersection(arr1, arr2, n);
	return 0;
}


