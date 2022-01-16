//find the min cost of matrix chain multiplication
//if there are n matrix in chain to be multiplied, what is the best order for matrix multiplication
// if there are A1 X A2 X A3
//then it can be multiplied in 2 ways: [  A1 x (A2 x A3) and (A1 x A2) x A3  ]
//both will give the same result, but both will take different time for computation.
//cost of both will be different.
//cost = number of scalar multiplication .
// choose the approach with minimum cost or minimum scalar multiplication.

#include<iostream>
using namespace std;
int main()
{
    //n stores the number of matrix we have.
    int n=4;
    //P array stores the dimensions of matrix in order .
    int p[5]={5,4,6,2,7};
    //lets make a n x n matrix to store the results.
    int M[n][n];
    //lets make another matrix to store the value of k i.e parenthesis point.
    int t[n][n];
    
    //for all i==j box, store 0, for no scalar multiplication,
    for(int i=0;i<n;i++)
      M[i][i]=0;
      
    //lets iterate over the matrix in diagonal fashion.
    for(int z=2;z<=n;z++)
    {
        //for each value in the diagonal
        for(int i=0;i<n-z+1;i++)
        {
            int j=i+z-1;
            //k is from 1 to j-1.
            int cost=9999999;
            int pt_point=0;
            
            //for each parenthesis point .
            for(int k=i;k<j;k++)
            {
                int temp = M[i][k] + M[k+1][j] + p[i]*p[k]*p[j];
                if (temp<cost)
                {
                    cost = temp;
                    pt_point=k;
                }
            }
            //select the minimum cost and store the respective value in M and t.
            M[i][j]=cost;
            t[i][j]=pt_point;
        }
    }
    
    cout<<"minimum number of scalar multiplication: "<<M[0][3];
}
