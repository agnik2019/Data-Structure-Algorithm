class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c: t) 
            mp[c]++;
        int windowStart = 0, matched = 0,substrStart = 0,minLength = s.length()+1;
        
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++)
        {
            char rightChar = s[windowEnd];
            if(mp.find(rightChar) != mp.end())
            {
                mp[rightChar]--;
                if(mp[rightChar] >= 0)
                    matched++;
            }
            while(matched == t.length())
            {
                if(minLength > windowEnd - windowStart+1)
                {
                    minLength = windowEnd - windowStart+1;
                    substrStart = windowStart;
                }
                char leftChar = s[windowStart++];
                if(mp.find(leftChar) != mp.end())
                {
                    if(mp[leftChar] == 0)
                        matched --; //before putting the character back,decrement the match count
                     
                    mp[leftChar]++;  //put the character back
                }
              
            }
        }
        return minLength > s.length()?"":s.substr(substrStart, minLength);
    }
};