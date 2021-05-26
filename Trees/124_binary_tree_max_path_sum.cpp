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
    int solve(TreeNode* currnode, int &globalMaximum)
    {
        if(!currnode) return 0;
        int maxpathsumfromleft = solve(currnode->left, globalMaximum);
        int maxpathsumfromright = solve(currnode->right, globalMaximum);
        
        maxpathsumfromleft = max(0,maxpathsumfromleft);
        maxpathsumfromright = max(0, maxpathsumfromright);
        
        // ignore paths with negative sums
        int localMaximum = maxpathsumfromleft+maxpathsumfromright+ currnode->val;
        globalMaximum = max(localMaximum,globalMaximum);
        
        return max(maxpathsumfromleft,maxpathsumfromright)+currnode->val;
        
                
    }
    int maxPathSum(TreeNode* root) {
            int globalMaximum = INT_MIN;
            int x = solve(root, globalMaximum);
            return globalMaximum;
        
    }
};