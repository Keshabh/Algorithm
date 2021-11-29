//using n traversals to find min and max elements in an array
#include<iostream>
using namespace std;
int main()
{
    int n=9,max,min;
    int arr[n]={5,3,1,7,2,6,18,9,6};
    
    //lets first display the array
    cout<<"Array: ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    
    //initialize min and max with array's 1st element
    max=arr[0];
    min=arr[0];
    
    //traverse in the array i.e O(n) times to compare each value with min and max
    //if ith element < min, then min=arr[i]
    //if ith element >max, then max=arr[i]
    
    for(int i=0;i<n;i++)
    {
        //for min
        if(arr[i]<min)
         min=arr[i];
        //for max
        if(arr[i]>max)
         max=arr[i];
    }
    
    //display max and min value 
    cout<<"\nMin: "<<min;
    cout<<"\nMax: "<<max;
}
