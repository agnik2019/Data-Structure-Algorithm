class Solution {
public:
    void solve(vector<int> &nums,int l, int h, vector<vector<int>> &chosen)
    {
        if(l == h) { chosen.push_back(nums); return; }
        for(int i = l; i< h; i++)
        {
            swap(nums[l],nums[i]);
            solve(nums,l+1,h,chosen);
            swap(nums[l], nums[i]);
        }
        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> chosen;
        solve(nums,0,nums.size(),chosen);
        return chosen;
    }
};





// Approach 2
class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &chosen, vector<int> &result)
    {
        if(nums.size() == 0) { chosen.push_back(result); }
        for(int i = 0; i< nums.size(); i++)
        {
            int digit = nums[i];
            nums.erase(nums.begin()+i);
            result.push_back(digit);
            solve(nums,chosen,result);
            result.pop_back();
            nums.insert(nums.begin()+i, digit);
        }
        

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> chosen;
        vector<int> result;
        solve(nums,chosen, result);
        return chosen;
    }
};