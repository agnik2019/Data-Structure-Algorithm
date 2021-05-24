class Solution {
public:
    
    vector<int> NGR(vector<int> nums)
    {
        vector<int> res(nums.size());
        stack<int> st;
        for(int i = nums.size()-1; i>= 0; i--)
        {
            while(st.size() > 0 && st.top() < nums[i]) st.pop();
            res[i] = st.size()>0 ? st.top() : -1;
            st.push(nums[i]);
        }
        return res;
    }

    vector<int> nextGreaterElement(vector<int>& query, vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ng = NGR( nums );
        for(int i = 0; i< nums.size(); i++)
            mp[nums[i]] = ng[i];
        
        vector<int> res(query.size());
        for(int i = 0; i< query.size(); i++)
            res[i] = mp[query[i]];
        return res;
        
    }
};