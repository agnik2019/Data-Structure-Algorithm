// Brute Force solution 

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target = nums;
        for(int i = 0; i< nums.size(); i++)
        {
            for(int j = index.size()-2; j>= index[i]; j-- )
                target[j+1] = target[j];
            target[index[i]] = nums[i];
        }
        return target;
    }
};

// Efficient Solution using c++ stl insert
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        
        vector<int> res;
        for(int i = 0; i< nums.size(); i++)
        {
            res.insert(res.begin()+ index[i], nums[i]);
        }
        return res;
    }
};