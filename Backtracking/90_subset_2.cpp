class Solution {
public:
  //  set<vector<in>>
    void solve(vector<int>& nums, int ind,vector<int> &curr, set<vector<int>> &res)
    {
        res.insert(curr);
        for(int i = ind; i<nums.size(); i++)
        {
            curr.push_back(nums[i]);
            solve(nums, i+1, curr, res);
            curr.pop_back();
        }
        return;
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        solve(nums, 0 , curr, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
        
    }
};