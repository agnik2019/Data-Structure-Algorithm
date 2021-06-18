class Solution {

public:
    bool palindrome(string &str, int i,int j)
    {
        while(i<j)
        {
            if(str[i] == str[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    void backtrack(string &s, int index,vector<vector<string>> &res, vector<string> &part )
    {
        if(index == s.length()) {
            res.push_back(part); //base contd
            return;
        }
        for(int i = index; i< s.length(); i++)
        {
            
            if(palindrome(s,index,i))
            {
                //choose --> explore---> unchoose
                part.push_back(s.substr(index, i-index+1));
                backtrack(s, i+1,res, part);
                part.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        backtrack(s,0,res,part);
        return res;
    }
};

