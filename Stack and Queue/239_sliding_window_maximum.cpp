// this is nlohn approach using multiset
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>> mp;
        vector<int> ans; 
        for(int i = 0; i<k; i++)
            mp.insert(nums[i]);
        ans.push_back(*mp.begin());
        for(int i = k; i< nums.size(); i++)
        {
            mp.erase(mp.lower_bound(nums[i-k]));
            mp.insert(nums[i]);
            ans.push_back(*mp.begin());
        }
        return ans;
    }
};




// o(n) solution using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for(int i = 0; i<k; i++)
        {
            while(!q.empty() and nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for(int i = k; i< nums.size(); i++)
        {
            if(q.front() == i-k) q.pop_front();
             while(!q.empty() and nums[q.back()] < nums[i])
                q.pop_back();
            
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};