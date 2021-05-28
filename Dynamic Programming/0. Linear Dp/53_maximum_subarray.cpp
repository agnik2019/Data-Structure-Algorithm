class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msf = INT_MIN;
        int meh = 0;
        for(int i = 0; i< nums.size(); i++)
        {
          meh = max(nums[i],meh+nums[i]);
          msf = max(msf, meh);
         }
    return msf;
    }
};