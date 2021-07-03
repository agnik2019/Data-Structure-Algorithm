class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return vector<int>{0,1};
        vector<int>prev = grayCode(n-1);
        
        for(int i=prev.size()-1;i>=0;i--)
            prev.push_back(prev[i]+pow(2,n-1));
        
        return prev;
    }
};