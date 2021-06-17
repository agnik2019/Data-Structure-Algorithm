class Solution {
public:
    void solve(int open, int close,vector<string>& res, string op){
        if(open == 0 && close == 0){
            res.push_back(op);
            return ;
        }
        if(open != 0)
            solve(open-1,close,res,op+"(");
        if(close > open)
            solve(open,close-1,res,op+")");
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        vector<string> res;
        string op="";
        solve(open,close,res,op);  
        return res;
    }
};