//divide and conquer method to perform binary search
#include<iostream>
using namespace std;
//binary search function
int bin_search(int arr[],int i,int j,int k)
{
    //calculate the mid value 
    int mid= (i+j)/2;
    //check if mid value == k
    if(arr[mid]==k)
      return mid+1;
    //stopping condition
    if(i>=j)
     return 0;
    //if k > arr[mid], call second half of the array
    if(k>arr[mid])
     return bin_search(arr,mid+1,j,k);
    else
     return bin_search(arr,i,mid-1,k);
}

//main
int main()
{
 int n=8,k;
 //binary search can only be applied on sorted array
 int arr[n]={1,3,7,23,45,55,89,101};
 //display the array
 cout<<"Array: ";
 for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";
 //read key value from user
 cout<<"\nEnter the value to be searched in the array: ";
 cin>>k;
 //call bin_search
 int val=bin_search(arr,0,n-1,k);
 if(val)
  cout<<"Element is found at position: "<<val;
 else
  cout<<"Element is not found.";
}
