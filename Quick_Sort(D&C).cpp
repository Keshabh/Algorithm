//quick sort that uses divide and conquer method to solve an array.
//it first does partition of the array into 2 halfs, i.e one sub-array is lesser than pivot value
//other half is greater than pivot
//and the recursion is then applied to both the halfs, until size of an element is 1.
//partition brings pivot value to its right place in the array.

#include<iostream>
using namespace std;

//partition function to partition the array.
//it returns the index of the partition value
//p=start index and r=end index of array A[]
int partition(int A[],int p,int r)
{
    //last element is chosen as pivot element i.e A[r]
    int x=A[r];
    //2 pointers are there i and j, which helps in partitiong.
    //i is initialized as p-1 and j is initialized as p
    int i=p-1;
    int j=p;
    //we will iterate from p till r-1, not r because r is a pivot value, which will be changed later
    for(j=p;j<r;j++)
    {
        //we will compare A[j] with pibot elemenet i.e x, 
        //if A[j]<=x, then we will increment i, and swap A[i] with A[j].
        if(A[j]<=x)
        {
            i++;
            //swap A[i] and A[j]
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
    //till ith index all the elements smaller than x are placed, we just need to place x on i+1 th index
    //swap A[i+1] with A[j]
    //j points to pivot value
    int t=A[j];
    A[j]=A[i+1];
    A[i+1]=t;
    
    //return pivot value index, which is there in i+1.
    return i+1;
}

//quick_sort function that performs recursion on 2 partitioned sub-arrays
void quick_sort(int A[],int p,int r)
{
    //stopping condition is, if we are just left with 1 elements
    if (p<r)
    {
        //partition returns the partitoning value index in q
        int q=partition(A,p,r);
        //apply recursion to first half i.e from p->q-1
        quick_sort(A,p,q-1);
        //apply recursion to second half i.e from q+1->r.
        quick_sort(A,q+1,r);
    }
}

//main
int main()
{
    int arr[]={44,  33,  11,  55,  77,  90,  40,  60,  99,  22,  88 };
    
    //display array before sorting
    cout<<"Before Sorting: ";
    for(int i=0;i<11;i++)
      cout<<arr[i]<<" ";
      
    //call quick_sort and pass array to be sorted
    //start index =0, end index=10.
    quick_sort(arr,0,10);
    
    //display array after Sorting
    cout<<"\n\nAfter Sorting: ";
    for(int i=0;i<11;i++)
      cout<<arr[i]<<" ";
}
