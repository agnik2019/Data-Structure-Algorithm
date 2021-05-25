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
    void dfs(TreeNode* root, string path, vector<string> &paths)
    {
        path =path+ to_string(root->val);
        if(!root->left && !root->right) paths.push_back(path);
        if(root->left) dfs(root->left,path+ "->", paths);
        if(root->right) dfs(root->right,path+ "->", paths);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path="";
        if(!root) return paths;
        else dfs(root, path, paths);
        return paths;
    }
};