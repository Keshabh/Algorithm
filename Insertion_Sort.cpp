//insertion sort to sort an array
#include<iostream>
using namespace std;
int main()
{
    int n=6;
    int arr[n]={22,41,63,14,56,36};
    //display elements before sorting
    cout<<"Elements before Sorting: ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      
    //sort Elements using two loops A/t insertion sort
    //Appraoch
    //pick ith element, compare it with its previous value, if wrong order, swap it.
    //Overall: pick and element and put it in its right position.
    //we will start with 2nd element, because we will have to compare it with its previous value.
    for(int i=1;i<n;i++)
    {
        //comapre jth element with its previous value from ith position till 0th position
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                //swap, as they are in wrong order
                int t=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
            }
            else
            {
                //else will only work if previous value is smaller than jth value
                //then we dont need to check its previous value, as they are already sorted till ith then.
                //just break the inner loop
                break;
            }
        }
    }
    
    //display elements after sorting
    cout<<"\n\nElements after Sorting: ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
