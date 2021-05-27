class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstoccur = -1;
        int lastoccur = -1;
        vector<int> res;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end)
        {
            int mid = start +(end - start)/2;
            if(nums[mid] == target)
            {
                firstoccur = mid;
                end = mid-1;
            }
            else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        res.push_back(firstoccur);
        start = 0;
         end = nums.size()-1;
        while(start <= end)
        {
            int mid = start +(end - start)/2;
            if(nums[mid] == target)
            {
                lastoccur = mid;
                start = mid+1;
            }
            else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        res.push_back(lastoccur);
        return res;
    }
};