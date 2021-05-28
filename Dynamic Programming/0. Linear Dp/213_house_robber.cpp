class Solution {
public:
    int robhelper(vector<int>& nums, int l, int h) {
        vector<int> dp(h+1);
        dp[l] = nums[l];
        dp[l+1] = max(nums[l+1], nums[l]);
        for(int i = l+2; i<= h; i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[h];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        return max(robhelper(nums,0,nums.size()-2),robhelper(nums,1,nums.size()-1) );
    }
};