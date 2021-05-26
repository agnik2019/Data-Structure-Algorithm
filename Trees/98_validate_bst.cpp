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
    
    void inorder(TreeNode* root,vector<int> &result)
    {
        if(!root) return ;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
    bool isValidBST(TreeNode* root) {
        
        vector<int> in ;
        inorder(root,in);
        int temp = in[0];
        for(int i = 1; i<in.size(); i++)
        {
            if(temp>=in[i]) {
                return false;
                break;
            }
            temp = in[i];
        }
        return true;

   }

};
