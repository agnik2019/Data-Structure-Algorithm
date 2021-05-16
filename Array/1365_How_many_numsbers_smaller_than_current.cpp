class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
       int count[101] = {0};
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++)
            count[nums[i]]++;
        
        for(int i = 1; i<101; i++)
            count[i] += count[i-1];
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                ans.push_back(0);
            else
                ans.push_back(count[nums[i]-1]);
        }
        
        return ans;
    }
};

// Approach 2: USING HASHMAP
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto x : nums)
            mp[x]++;
        for(auto num : nums)
        {
            int temp = 0;
            
            for(auto j : mp)
            {
                if(j.first < num)
                    temp+= j.second;
            }
            res.push_back(temp);
        }
        return res;
    }
};