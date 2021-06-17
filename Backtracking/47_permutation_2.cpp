class Solution {
public:
    void solve(vector<int> &nums, int l, int h, set<vector<int>> &chosen)
    {
        if(l == h)
        {
            chosen.insert(nums);
            return;
        }
        for(int i = l ; i< h; i++)
        {
            swap(nums[i], nums[l]);
            solve(nums, l+1,h,chosen);
            swap(nums[i], nums[l]);
        }      
        return;
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> chosen;
        solve(nums,0, nums.size(), chosen);
        vector<vector<int>> result(chosen.begin(), chosen.end());
        return result;
    }
};