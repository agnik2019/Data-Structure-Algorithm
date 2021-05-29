class Solution {
public:
    int memo[501][501];
    int solve(vector<int>& arr,int i, int j)
    {
        if(i>j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
           int max = INT_MIN;
           for(int k = i; k<=j; k++)
           {
               int temp = solve(arr,i,k-1)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j+1];
               if(temp> max) max = temp;
           }
           return memo[i][j]= max;
    }
    int maxCoins(vector<int>& nums) {
        memset(memo,-1, sizeof(memo));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(nums,1,nums.size()-2);
    }
};