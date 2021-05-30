/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct_tree_from_arr(vector<int>& nums, int left, int right)
    {
        if(left>right) return NULL;
        int mid = right +(left - right)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = construct_tree_from_arr(nums,left,mid-1);
        node->right = construct_tree_from_arr(nums,mid+1,right);              
        return node;
        
    }
    
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        else return construct_tree_from_arr(nums, 0, nums.size()-1);
        
    }
};