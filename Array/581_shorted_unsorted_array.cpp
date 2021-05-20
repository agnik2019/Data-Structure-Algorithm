class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int i = 0, j = nums.size()-1;
        while(i < nums.size() && nums[i] == sorted[i])
            i++;
        while(j> i && nums[j] == sorted[j])
            j--;
        return j-i+1;
        
    }
};