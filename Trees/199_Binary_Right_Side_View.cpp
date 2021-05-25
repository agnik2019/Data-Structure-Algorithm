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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        res.push_back(root->val);
        while(!q.empty())
        {
            int levelsize = q.size();
            vector<TreeNode*> level;
            for(int i = 0; i<levelsize; i++)
            {
                TreeNode* currentNode = q.front();
                q.pop();
                if(currentNode->left) {
                    q.push(currentNode->left);
                    level.push_back(currentNode->left);   
                }
                if(currentNode->right){
                    q.push(currentNode->right);
                    level.push_back(currentNode->right);  
                }
            }
            for(int i = 0; i<level.size(); i++)
            {
                if(i+1 == level.size()){
                    res.push_back(level[i]-> val);
                    break;
                }
            }
            
        } 
        return res;
        
    }
};








// Another same solution with little change
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size(), val =-1;
            for(int i = 0 ;i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(i == size-1)   val = node->val;

                if(node->left) q.push(node->left);
                                
                if(node->right) q.push(node->right);
                               
            } 
            result.push_back(val);
        }
        return result;
        
    }
};