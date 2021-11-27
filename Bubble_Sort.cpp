//bubble sort to sort the array
#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int arr[n]={16,36,24,37,15};
    //display array
    cout<<"Before Sorting: ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      
    //we will have to iterate through 2 loops for sorting in bubble sort
    //in each iteration we go through each element and make it bubble element and compare it with its next element
    //and if its in wrong order, we swap them.
    //we will iterate for n-1 times, because in every iteration,largest element reaches the end.
    //so if n-1 element in n-1 iteration reaches their end or their correct position, then element in 1st 
    //position is obviosuly is in its right position.
    //and in each iteration 1 element is sorted, so we will traverse for only n-ith time in each iteration, avoiding last sorted elements.
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            //comapre jth and j+1th element
            if(arr[j]>arr[j+1])
            {
                //if wrong order i.e in decreasing order, swap them and turn it into ascending order
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    //display sorted array
    cout<<"\n\nAfter Sorting: ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
