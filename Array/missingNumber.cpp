class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
                
        unordered_map<int,int> mp(n);
        
        for(int i = 0; i<n ; i++)
            mp[nums[i]]++;
        
        for(int i = 0; i<n+1; i++)
        {
            if(mp.find(i) == mp.end()) // if the number not present in array
                return i;
        }
        return -1;
        
    }
};