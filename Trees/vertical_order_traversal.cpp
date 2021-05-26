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
   void findMinMax( TreeNode*node, int *min, int *max, int hd)
{
    
    if (node == NULL) return;
 
    
    if (hd < *min)  *min = hd;
    else if (hd > *max) *max = hd;
 
    
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}

void printVerticalLine(TreeNode *node, int line_no, int hd,vector<int> &t)
{
    if (node == NULL) return ;
 
    if (hd == line_no){

        t.push_back(node->val);
    }
    
    printVerticalLine(node->left, line_no, hd-1,t);
    printVerticalLine(node->right, line_no, hd+1,t);    
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> t;
        int min = 0, max = 0,line_no;
        findMinMax(root, &min, &max, 0);

        for (line_no = min; line_no <= max; line_no++)
        {
            printVerticalLine(root, line_no, 0,t);
            res.push_back(t);
            t.clear();
        }
        return res;
    }
};

