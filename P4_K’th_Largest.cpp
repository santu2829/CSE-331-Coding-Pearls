//C++ program for K’th Largest element in array
#include <bits/stdc++.h>
using namespace std;
int parent(int i)
{
     return (i-1)/2;
}
int left(int i)
{
     return (i*2)+1;
}
int right(int i)
{
     return (i*2)+2;
}
void swap(int *a,int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}
void insert(int heap[],int *size, int val)
{
     heap[*size]= val;
     int i = *size;
     (*size)++;
     while(i!=0 && heap[parent(i)]>heap[i])
     {
     swap(&heap[parent(i)],&heap[i]);
     i = parent(i);
     }
}
void heapify(int heap[],int i,int size)
{
     int l = left(i);
     int r = right(i);
     int lar = i;
     if(lar<size && heap[l]<heap[i])
        lar = l;
     if(r<size && heap[r]<heap[lar])
        lar = r;
     if(lar!=i)
     {
     swap(&heap[i],&heap[lar]);
     heapify(heap,lar,size);
     }
}
int extract(int heap[],int *size)
{
     int root = heap[0];
     heap[0] = heap[*size-1];
     (*size)--;
     heapify(heap,0,*size);
     return root;
}
 int main()
 {
   int n,k;
   cin>>n>>k;
   int *heap = (int *)malloc(sizeof(int)*n);
   int size = 0;
   for(int i=0;i<n;i++)
   {
   int t;
   cin>>t;
   insert(heap,&size,t);
   }
    while(--k)
    {
     extract(heap,&size);
    }
    cout<<extract(heap,&size)<<endl;
}
