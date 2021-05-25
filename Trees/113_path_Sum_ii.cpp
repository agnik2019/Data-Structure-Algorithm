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
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>> &paths )
    {
        if(!root) return ;  //BASE CASE
        
        path.push_back(root -> val); //WHAT SHOULD WE DO FIRST
        
        //GOAL STATE
        if(root->val == sum && !root->left && !root->right)
                     paths.push_back(path);
        //MAGICAL RECUSIVE FUNCTION
        dfs(root->left, sum - root->val, path, paths);
        dfs(root->right,sum - root->val ,path, paths);
        path.pop_back();  //BACKTRACK
   
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> paths;
        dfs(root, sum, path, paths);
        return paths;

        
    }
};