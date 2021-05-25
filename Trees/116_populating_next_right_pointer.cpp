/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        root->next = NULL;
        while(!q.empty())
        {
            int levelsize = q.size();
            vector<Node*> level;
            for(int i = 0; i<levelsize; i++)
            {
                Node* currentNode = q.front();
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
                    level[i]-> next = NULL;
                    break;
                }
                level[i]->next = level[i+1];
            }
            
        } 
        return root;
        
    }
};