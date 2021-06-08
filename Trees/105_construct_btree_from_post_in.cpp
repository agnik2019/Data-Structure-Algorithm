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
    TreeNode* buildTreehelper(vector<int>& postorder, vector<int>& inorder,int start,int end,int &idx)
{
    if(start > end) return NULL;
    int cur = postorder[idx],pos;
    for(int i = start; i<=end; i++)
        if(inorder[i] == cur) {
            pos= i;
            break;
        }
    idx--;
    TreeNode* node = new TreeNode(cur);
    node->right = buildTreehelper(postorder,inorder,pos+1,end,idx);
     node->left = buildTreehelper(postorder,inorder,start,pos-1,idx);
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
                int idx = inorder.size()-1;
        return buildTreehelper(postorder,inorder,0,inorder.size()-1,idx);
        
    }
};