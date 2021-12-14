//fractional knapsack problem using greedy approach
//here a sack is there with capacity W weigh to hold items.
//we have n items with its cost and weight.
//then what items should i put in my sack, so that i maximize the profit out of it as a theif.
//finding the ration of cost/weight of a item will tell us, how much expensive a product is.
//first we will find the ratio of profit/weight of each item and sort all the items in descending order with their ratio.
//by this, we will be choosing the task expensive items first, and so on smaller cost items.
#include<iostream>
using namespace std;

int main()
{
    //store item number, its profit, its weight.
    //we have 7 items.
    int item[]={1,2,3,4,5,6,7};
    int profit[]={5,10,15,7,8,9,4};
    int weight[]={1,3,5,4,1,3,2};
    //knapsack weight 
    int W=15;
    //total_cost variable to store the totak cost.
    int total_cost=0;
    
    //find the profit/weight ratio for each item and store it in ratio array.
    int ratio[7];
    for(int i=0;i<7;i++)
      ratio[i]=profit[i]/weight[i];
    
    //sort the items data in descending order w.r.t its ratio value.
    //lets sort it using bubble sort.
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7-i-1;j++)
        {
            if(ratio[j]<ratio[j+1])
            {
                //sort in descending order.
                //swap ratio.
                int t=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=t;
                
                //swap profit values
                t=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=t;
                
                //swap weight values
                t=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=t;
                
            }
        }
    }
    
    //lets make a variable rem_wait to store the remaining weight of the knapsack.
    //initially rem_wait = W i.e knapsack weight
    int rem_wt=W;
    //iterate through each item till remaining weight >0, or no item is left.
    int i=0;
    while (i<7 && rem_wt>0)
    {
        //select the item if rem_wt > items_weight.
        if(rem_wt>=weight[i])
        {
            //add the items_cost to total_cost
            //subtract the remaining weight value by items_weight.
            total_cost+=profit[i];
            rem_wt-=weight[i];
        }
        else
        {
            //we enter else only if we have to take fractional value of the item.
            //remaining weight/items weight fraction of profit will be added to total_cost.
            //if fraction value is added, it means it's the last item that can be added to the sack,
            //so make remaining weight to be 0.
            total_cost+=profit[i]*(rem_wt/weight[i]);
            rem_wt=0;
        }
        i++;
    }
    
    //display the total_cost
    cout<<"The Maximum Profit made by theif: "<<total_cost;
    
    
}
