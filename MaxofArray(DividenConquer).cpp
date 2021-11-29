//min-max problem using divide and conquer, where we will focusing on finding the maximum number
#include<iostream>
using namespace std;

int Max(int arr[], int i,int j)
{
    if(i==j)
      return arr[i];
    //find the mid point of the array to divide array into 2 parts
    int mid = (i+j)/2;
    //1st sub array
    int val1 = Max(arr,i,mid);
    int val2 = Max(arr,mid+1,j);
    //compare both values and return the max value
    return val1>val2?val1:val2;
}

int main()
{
    int n=9;
    int arr[n]={5,3,1,7,2,6,18,9,6};
    int start_index=0;
    int end_index=n-1;
    //display all the elements
    cout<<"Array: ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    cout<<"\n\nMaximum Element of the array is: "<<Max(arr,start_index,end_index);
}
