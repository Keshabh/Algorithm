//activity selection problem for a resource, using greedy approach
//we have n tasks, where each task has its own start and end time.
//and we are going to select the max number of task that can be used by a single resource wihtout any collision of task

#include<iostream>
using namespace std;

int main()
{
    //task, their start and end time array.
    int task[]={1,2,3,4,5,6,7,8,9,10};
    int start[]={1,2,3,4,7,8,9,9,11,12};
    int end[]={3,5,4,7,10,9,11,13,12,14};
    
    //using greedy approach, we need to fill resource with new task as soon as possible.
    //for that we should be focusing on when the task is ending, so the next after that can be assigned next.
    //so we should be sorting our task, w.r.t its end time.
    
    //sorting all arrays w.r.t end[].
    //applying buuble sort
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10-i-1;j++)
        {
            if(end[j]>end[j+1])
            {
                //swap end
                int t=end[j];
                end[j]=end[j+1];
                end[j+1]=t;
                
                //swap tasks
                t=task[j];
                task[j]=task[j+1];
                task[j+1]=t;
                
                //swap start time
                t=start[j];
                start[j]=start[j+1];
                start[j+1]=t;
                
            }
        }
    }
    
    //there should be a bucket to keep all the task that gets to use the resource(the one that does not collides)
    //let that bucket be array A[]
    int A[10];
    //first task i.e task[0] will be assigned first to the array.
    A[0]=0; //1st task is assigned.
    
    //lets make a variabel to store previous stored task end time.
    int end_time=end[0];
    
    //lets make a variable for A's index.(which will aslo indicate the number of task in A.)
    int k=0;
    
    //iterate from 2nd task till end
    for(int i=1;i<10;i++)
    {
        //criteria for the task is:
        //new task start time >= previous stored task end time.
        if (start[i]>=end_time)
        {
            //increment k i.e A's index.
            //put this task in A bucket
            //change the end_time to this task's end time.
            k++;
            A[k]=i;//we are storing the task's index in A.
            end_time=end[i];
            
        }
    }
    
    //lets display all the task we have in A.
    cout<<"Final Activity Schedule:";
    for(int i=0;i<=k;i++)
      cout<<"\nTask: "<<task[A[i]];
}
