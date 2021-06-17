class Solution {
public:
    void solve(string &digits,int index,vector<string>& ip, vector<string>& res, string &curr)
    {
        if(index == digits.size())
        {
            res.push_back(curr);
            return;
        }
        string c = ip[digits[index]-'0'];
        for(int i = 0; i< c.size(); i++)
        {
                    curr.push_back(c[i]);
                    solve(digits, index+1, ip,res,curr);
                    curr.pop_back();
        }
        return;
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ip ={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string curr;
        solve(digits,0,ip,res,curr);
        return res;
    }
};