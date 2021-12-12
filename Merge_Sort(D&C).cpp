//merge sort to sort the array
#include<iostream>
using namespace std;

//merge function to merge two sorted arrays
void merge(int A[],int p,int q,int r)
{
    //initialize 2 arrays so that it can be used to merge it in the real array 
    int x[20],y[20];
    int k=0;
    //copy elements from array A[p->q] in x, and A[q+1->r] in y
    for(int i=p;i<=q;i++)
    {
        x[k]=A[i];
        k++;
    }
    //put a bigger value at at the end of an array for further merge purpose
    x[k]=999999;
    
    //similarly for y
    k=0;
    for(int i=q+1;i<=r;i++)
    {
        y[k]=A[i];
        k++;
    }
    //put a bigger value at at the end of an array for further merge purpose
    y[k]=999999;
    
    //merge part to sort 2 sorted arrays from p->r
    int i=0,j=0;
    for(int k=p;k<=r;k++)
    {
        //find the smallerst amonng x[i] and y[j]
        //the one smaller, they will be assigned to A[k] and their index will increment by 1
        if(x[i]<=y[j])
        {
            A[k]=x[i];
            i++;
        }
        else
        {
            A[k]=y[j];
            j++;
        }
    }
}


//recursive merge_sort() function to decompose array into sub-arrays.
void merge_sort(int A[],int p,int r)
{
    //recursion stoppping condition is: if we are just left with 1 element
    if(p<r)
    {
        //find the mid index to split the array
        int q=(p+r)/2;
        //call recursion for 1st part of array from p --> q
        merge_sort(A,p,q);
        //call recursion for 2nd part of the array from q+1 --> r
        merge_sort(A,q+1,r);
        //call merge function to sort the sub-array from p->q and q+1->r into main array from p->r
        merge(A,p,q,r);
    }    
}


//main
int main()
{
    //initialize an array
    int arr[]={36,25,40,2,7,80,15};
    
    //display unsorted array
    cout<<"Before Sorting :";
    for(int i=0;i<7;i++)
      cout<<arr[i]<<" ";
      
    //start_index i.e p=0, and end_index=6
    //call merge_sort to sort the function
    merge_sort(arr,0,6);
    
    //display the sorted array
    cout<<"\n\nAfter Sorting :";
    for(int i=0;i<7;i++)
      cout<<arr[i]<<" ";
}
