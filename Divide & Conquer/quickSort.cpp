class Solution {
public:
    // int partitionIndex(vector<int>& nums, int low, int high){
    //     int index = low-1;
    //     for (int j=low;j<=high;j++){
    //         if (nums[j]<= nums[high]){
    //             index++;
    //             swap(nums[index], nums[j]);
    //         }
    //     }
    //     return index;
    // }
    int partitionIndex(vector<int>& nums, int low, int high){
        int randIndex = low + rand()%(high-low+1);
        swap(nums[randIndex], nums[high]);
        int index = low-1;
        for (int j=low;j<=high;j++){
            if (nums[j]<= nums[high]){
                index++;
                swap(nums[index], nums[j]);
            }
        }
        return index;
    }
    void quickSortHelper(vector<int>& nums, int low, int high){
        if (low<high){
            int p = partitionIndex(nums, low, high);
            quickSortHelper(nums, low, p-1);
            quickSortHelper(nums, p+1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSortHelper(nums,0,nums.size()-1);
        return nums;
    }
};