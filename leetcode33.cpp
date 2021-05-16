#include<iostream>
using namespace std;
#include<vector>
    int bsearch(vector<int> &nums,int start, int end, int ele)
    {
         while(start<=end)
        {
            int mid = end+(start-end)/2;
            if(ele == nums[mid])
                return mid;
            if(ele < nums[mid])
                end = mid-1;
            else if(ele > nums[end])
                 start = mid+1;
                
         }
        return -1;
    }
    int search(vector<int>& nums, int target)
     {
        int start = 0;
        int end = nums.size()-1;
        int n = nums.size();
        int pivot = 0;
        while(start<=end)
        {
            int mid = end+(start-end)/2;
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;
            if(nums[mid] <= nums[next] && nums[mid]<=nums[prev])
                pivot = mid;
            if(nums[start] <= nums[mid])
                start = mid+1;
            else if(nums[mid] <= nums[end])
                end = mid-1;
         }
        int ans = bsearch(nums, 0,pivot-1, target);
        
        if(ans == -1) ans = bsearch(nums,pivot, n-1, target);
        
        return ans;
        
    }

int main();
{
    vector<int> v ={4,5,6,7,0,2,3};
    return search(v, 2);

}