class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> mp;
        for(char c: p) 
            mp[c]++;
        int windowStart = 0, matched = 0;
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++)
        {
            char rightChar = s[windowEnd];
            if(mp.find(rightChar) != mp.end())
            {
                mp[rightChar]--;
                if(mp[rightChar] == 0)
                    matched++;
            }
            if(matched == (int)mp.size())  //have we find the anagram
                res.push_back(windowStart);
            if(windowEnd >= p.length()-1)  // shrink the window
            {
                char leftChar = s[windowStart++];
                if(mp.find(leftChar) != mp.end())
                {
                    if(mp[leftChar] == 0)
                        matched --; //before putting the character back,decrement the match count
                     
                    mp[leftChar]++;  //put the character back
                }
              
            }
        }
        return res;
        
    }
};