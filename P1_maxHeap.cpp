// C++ program for Max Heap
#include<iostream>
using namespace std;
void maxHeap(int arr[],int n,int i)
{
	int largest = i;
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	if (l < n && arr[l]>arr[largest])
		largest = l;
	if (r < n && arr[r]>arr[largest])
		largest = r;
	if (largest != i) 
	{		
		swap(arr[i],arr[largest]);
		maxHeap(arr,n,largest);
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
	cout<<"MaxHeap is\n";
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

