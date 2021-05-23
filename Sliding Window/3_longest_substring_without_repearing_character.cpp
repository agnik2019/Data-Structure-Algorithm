class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart = 0, maxLength = 0;
        unordered_map<char, int> mp;
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++)
        {
            char rightChar = s[windowEnd];
            if(mp.find(rightChar) != mp.end())
                windowStart = max(windowStart, mp[rightChar]+1);
            mp[rightChar] = windowEnd;
            maxLength = max(maxLength, windowEnd-windowStart+1);
        }
        return maxLength;
    }
};