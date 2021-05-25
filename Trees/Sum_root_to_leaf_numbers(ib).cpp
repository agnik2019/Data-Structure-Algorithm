/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int solve(TreeNode* A, int val)
 {
     if(!A) return 0;
     int temp = (((val*10)%1003) + A->val)%1003;
     if(A->left ==NULL && A->right == NULL)
        return temp;
     int l = solve(A->left,temp);
     int r = solve(A->right,temp);
     return (l+r)%1003;
 }
 
int Solution::sumNumbers(TreeNode* A) {
    return solve(A,0);
}
