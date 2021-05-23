class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int windowStart = 0, maxLength = 0, maxonecount = 0;
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            if(nums[windowEnd] == 1)
                maxonecount++;
            if(windowEnd-windowStart+1-maxonecount > k)
            {
                if(nums[windowStart] == 1)
                    maxonecount--;
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd-windowStart+1);
        }
        return maxLength;
    }
};