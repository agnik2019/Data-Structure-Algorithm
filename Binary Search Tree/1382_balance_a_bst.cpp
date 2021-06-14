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
    vector<TreeNode*> in;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        in.push_back(root);
        inorder(root->right);
    }
    TreeNode* constructTree(int start , int end)
    {
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = in[mid];
        root->left = constructTree(start,mid-1);
        root->right = constructTree(mid+1,end);
        return root;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        inorder(root);
        root = constructTree(0, in.size()-1);
        return root;       
    }
};