//selection sort
#include<iostream>
using namespace std;
int main()
{
    int n=5,minimum;
    int arr[n]={7,4,3,6,5};
    //display all elements before sorting
    cout<<"Elements before sorting: ";
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    
    //apply selection sort to sort array arr
    //uses two loops , and in each iteration it puts the minimum value of the sub array in its right position
    //we will select ith position element as temporaray minimum element
    // we will compare it with all the elements from ith position till end to find the min value
    //then we will swap the min value with ith position element
    //in each iteration, 1 element goes to its right position, so putting 4 elements in its right position 
    //means we dont have to put the 5th in its right position, it will be already sorted
    
    for(int i=0;i<n-1;i++) 
    {
        //select ith as min value
        minimum = arr[i];
        //iterate from ith till end and compare and get the min value
        for(int j=i;j<n;j++)
        {
            if (arr[j]<minimum)
            {
                minimum=arr[j];
                //swap min value with ith index, i.e swap arr[j] and arr[i]
                int t=arr[j];
                arr[j]=arr[i];
                arr[i]=t;
            }
        }
    }
    
    //display sorted elements
    cout<<"\n\nElements after sorting: ";
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
}
