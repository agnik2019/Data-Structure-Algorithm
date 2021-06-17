class Solution {
public:
    void findcombinations(vector<int>& candidates, int index,int target,vector<int> &combos,vector<vector<int>> &result )
    {
        //base contd.
        if(target == 0) 
        {
            result.push_back(combos);
            return;
        }
        if(target < 0) return;
        for(int i = index; i< candidates.size(); i++)
        {
             combos.push_back(candidates[i]);
             findcombinations(candidates,i,target-candidates[i],combos,result);
            combos.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combos;
        findcombinations(candidates,0, target,combos,result);
        return result;
    }
};