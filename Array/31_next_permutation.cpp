class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        // find the peak element
        int lastinc = -1;
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                lastinc = i;
        }
        // if the array is in descending order
        if(lastinc == -1)
        {
            for(int i = 0; i<nums.size()/2; i++)
                swap(nums[i], nums[nums.size()-i-1]);
            return;
        }
        int index = lastinc;
        for(int  i = lastinc; i<nums.size(); i++)
            if(nums[i]>nums[lastinc-1] and nums[i]<nums[index])
                index = i;
        // swapping
        swap(nums[lastinc-1], nums[index]);
        sort(nums.begin()+lastinc, nums.end());
        
    }
};