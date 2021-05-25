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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int minDepth = 0;
        while(!q.empty())
        {
            int levelsize = q.size();
            minDepth++;
            for(int i = 0; i<levelsize; i++)
            {
                TreeNode* currentNode = q.front();
                q.pop();
                if(!currentNode->left && !currentNode->right)
                    return minDepth;
                if(currentNode->left) q.push(currentNode->left); 
                if(currentNode->right) q.push(currentNode->right); 

            }
        }
        return minDepth;
        
    }
};