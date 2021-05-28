class Solution {
public: 
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for(int i =0;i< nums.size();i++) 
            sum+=nums[i];
        if(sum%2 != 0)
            return false;
      
        sum = sum/2;  
        int n = nums.size();
        bool t[n+1][sum+1];
        for(int i =0;i<= nums.size();i++)
        {
            for(int j = 0;j<=sum;j++)
            {
                if(i==0) 
                    t[i][j]=false;
                if(j==0) t[i][j] = true;
            }
        }
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=sum;j++)
            {
                if(nums[i-1] <= j) t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
                
        return t[n][sum];
    }
};