class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        vector<int> res;

        for(auto word : words)
            mp[word]++;
        if(s.length()==0 || words.size() == 0)
            return res;
        int wordsCount = words.size();
        int wordLength = words[0].length();
        for(int i = 0; i< s.length()-wordsCount*wordLength+1; i++)
        {
            unordered_map<string,int> wordSeen;
            for(int j = 0; j<wordsCount; j++)
            {
                int nextWordIndex = i+j*wordLength;
                string word = s.substr(nextWordIndex, wordLength);
                if(mp.find(word) == mp.end())
                        break;
                wordSeen[word]++;
                if(wordSeen[word] > mp[word])
                         break;
                if(j+1 == wordsCount)
                    res.push_back(i);
                }
            
            }
        return res;
    }
};