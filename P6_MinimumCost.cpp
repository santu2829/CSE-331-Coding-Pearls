#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int MinimumCost(int arr[], int n) 
{
   priority_queue< int,vector<int>,greater<int>>queue(arr, arr+n);
   int minCost = 0;
   while (queue.size() > 1) 
   {              
      int item1=queue.top();            
      queue.pop();
      int item2=queue.top();          
      queue.pop();
      minCost+=item1+item2;         
      queue.push(item1+item2);
   }
   return minCost;
}
int main() 
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   	cin>>arr[i];
   cout<<"Total minimum cost: "<<MinimumCost(arr, n);
}
