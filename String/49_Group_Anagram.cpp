class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        string temp;
        int n = strs.size();
        for(int i = 0; i<n;i++)
        {
            temp =  strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        
        //temp - stores sorted word of array
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};