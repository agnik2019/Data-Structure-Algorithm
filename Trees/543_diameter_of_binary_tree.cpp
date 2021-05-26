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
    int calculateHeight(TreeNode* root, int &treeDiameter)
    {
        if(!root) return 0;
        int lefttreeheight = calculateHeight(root->left, treeDiameter);
        int righttreeheight = calculateHeight(root->right, treeDiameter);
        
        //diameter of the current node
        int diameter = lefttreeheight+righttreeheight+1;
        // update the global tree diameter
        treeDiameter = max(treeDiameter,diameter);
        
        // height of the current node
        return max(lefttreeheight,righttreeheight)+1;
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ;
        int treeDiameter = 0;
        int x = calculateHeight(root, treeDiameter);
        return treeDiameter-1;  //-1 because length = no of edges
        
    }
};