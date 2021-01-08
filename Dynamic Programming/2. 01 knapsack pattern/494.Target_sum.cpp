class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int diff) {
       // if(nums.size()==1) return 0;
        int total = 0;
        for(int i = 0; i< nums.size(); i++)
            total += nums[i];
        if(diff>total || (total+diff)&1)return 0;
        int sum = (diff+total)/2;
        int n = nums.size();
        int t[n+1][sum+1];
        for(int i = 0; i<= n ; i++ )
        {
            for(int j =0 ; j<= sum; j++ )
            {
               if(i==0) t[i][j] = 0;
               if(j==0) t[i][j] = 1;
                
            }
        }
        for(int i = 1; i<= n ; i++ )
        {
            for(int j =0 ; j<= sum; j++ )
            {
                if(nums[i-1] <= j)
                    t[i][j] = t[i-1][j-nums[i-1]]+t[i-1][j];
                else t[i][j]= t[i-1][j];
                
            }
        }
        return t[n][sum];
        
    }
};