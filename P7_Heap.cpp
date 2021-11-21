// C++ program for Array representation of Heap
#include<iostream>
using namespace std;
void maxHeap(int arr[],int n,int i)
{
	int smallest = i;
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	if (l < n && arr[l]<arr[smallest])
		smallest = l;
	if (r < n && arr[r]<arr[smallest])
		smallest = r;
	if (smallest != i) 
	{		
		swap(arr[i],arr[smallest]);
		maxHeap(arr,n,smallest);
	}
}
void buildHeap(int arr[], int n)
{
	int index=(n/2)-1;
	for(int i=index;i>=0;i--) 
	{
		maxHeap(arr, n, i);
	}
}
void printHeap(int arr[], int n)
{
	cout<<"Array representation of heap is\n";
	for(int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	buildHeap(arr, n);
	printHeap(arr, n);
	return 0;
}

