    #include<iostream>>
    using namespace std;
    #include<vector>
    #include<set>
    #include <numeric> 

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> mp;
        for(int i = 0; i< mat.size(); i++)
        {
            int sum = accumulate(mat[i].begin(), mat[i].end(),0);
            mp.insert({sum,i});
        }
         vector<int> res;
        for(auto it= mp.begin(); k > 0;it++,k--)
            res.push_back(it->second);
        
        return res;
        
    }