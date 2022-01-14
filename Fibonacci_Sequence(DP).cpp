//using dynamic approach for fibonacci sequence
//we use bottom-up approach i.e we solve small problems then we move to complex ones.
//we store solutions of sub-problems in an fiboay, so that re-computation is not done for complex problems 
//and time complexity is reduced by avoiding re-computation of same problems again and again.

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the length of fibonacci sequence: ";
    cin>>n;
    int fibo[n]; //to store the computed values so that it can be reused.
    
    //fibonacci: F(n) = F(n-1) + F(n-2)
    //first 2 of sequence.
    fibo[0]=0;
    fibo[1]=1;
    //lets compute fibonacci
    for (int i=2;i<=n;i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2]; 
    }
    
    //lets print the fibonacci sequence.
    cout<<"\nFibonacci Sequence: ";
    for(int i=0;i<n;i++)
       cout<<fibo[i]<<" ";
}
