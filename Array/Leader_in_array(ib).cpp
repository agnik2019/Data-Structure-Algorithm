// Problem Description

// Given an integer array A containing N distinct integers, you have to find all the leaders
// in the array A.

// An element is leader if it is strictly greater than all the elements to its right side.

vector<int> Solution::solve(vector<int> &nums) {
   int rmax = 0;
    vector<int>res;
    for(int i=nums.size()-1;i>=0;i--)
    {
        if(nums[i]>rmax)
            res.push_back(nums[i]);
        rmax = max(rmax, nums[i]);
    }
    return res;
}
