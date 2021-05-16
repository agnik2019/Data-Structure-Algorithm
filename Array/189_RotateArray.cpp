class Solution {
public:
    void rev(vector<int> &arr, int l, int r)
    {
        while(l<r)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++; r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
        k = k%n;
        rev(nums,0,n-k-1);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);
        // reverse(nums.begin(), nums.begin()+n-k);
        // reverse(nums.begin()+n-k, nums.end());
        // reverse(nums.begin(), nums.end());   
    }
};