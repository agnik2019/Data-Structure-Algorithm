#define in pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i = 0; i< nums.size(); i++)
            mp[nums[i]]++;
        priority_queue<in,vector<in>,greater<in>> minh;
        for(auto i = mp.begin(); i!= mp.end(); i++)
        {
            minh.push({i->second, i->first});
            if(minh.size() > k)
                minh.pop();
        }
        while(!minh.empty())
        {
            result.push_back(minh.top().second);
            minh.pop();
        }
        return result;
    }
};