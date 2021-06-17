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
           if(i > index && candidates[i] == candidates[i-1]) continue; 
             combos.push_back(candidates[i]);
             findcombinations(candidates,i+1,target-candidates[i],combos,result);
            combos.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combos;
        sort(candidates.begin(), candidates.end());
        findcombinations(candidates,0, target,combos,result);
        return result;
    }
};