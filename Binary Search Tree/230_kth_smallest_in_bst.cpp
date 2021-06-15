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
 int count = 0 ;
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* res = kthsmall(root,k);
        return res->val;
        
    }
    TreeNode* kthsmall(TreeNode* root, int k)
    {
        if(!root) return NULL;
        
        TreeNode* left = kthsmall(root->left,k);
        if(left) return left;
        count++;
        if(count == k) return root;
        return kthsmall(root->right,k);
           
    }
};