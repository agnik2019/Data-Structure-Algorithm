#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &val, vector<int> &nums, int sum) {
   
        int n = nums.size();
        int t[n+1][sum+1];
        for(int i =0;i<= nums.size();i++)
        {
            for(int j = 0;j<=sum;j++)
            {
                if(i==0 || j==0) 
                    t[i][j]=0;
            }
        }
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=sum;j++)
            {
                if(nums[i-1] <= j) 
                    t[i][j]=max(val[i-1]+t[i-1][j-nums[i-1]] , t[i-1][j]);
                else
                    t[i][j]=t[i-1][j];
            }
        }
                
        return t[n][sum];
}
int main()
{
    vector<int> profit = {1,6,10,16};
    vector<int> weight = {1,2,3,5};
    cout <<"knapsack  "<<knapsack(profit, weight, 6)<<endl;
    return 0;

}