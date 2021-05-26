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
    int pathSumHelper(TreeNode* currnode, int S, vector<int> &paths)
    {
        if(!currnode) return 0;
        paths.push_back(currnode->val);
        int pathsum = 0, pathcount = 0;
        for(vector<int>::reverse_iterator itr = paths.rbegin(); itr!= paths.rend(); itr++)
        {
            pathsum += *itr;
            if(pathsum == S) pathcount++;
        }
        pathcount += pathSumHelper(currnode->left, S,paths);
        pathcount += pathSumHelper(currnode->right, S,paths);
        paths.pop_back();
        return pathcount;

    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> paths;
        return pathSumHelper(root, targetSum, paths);
        
    }
};