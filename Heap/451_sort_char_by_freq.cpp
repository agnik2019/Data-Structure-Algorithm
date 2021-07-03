#define in pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        priority_queue<in> maxh;
        for(auto i = mp.begin(); i!= mp.end(); i++)
        {
            maxh.push({i->second, i-> first});
        }
        while(!maxh.empty())
        {
            char c = maxh.top().second;
            int freq = maxh.top().first;
            maxh.pop();
            while(freq--)
                ans+= c;
        }
        return ans;
    }
};