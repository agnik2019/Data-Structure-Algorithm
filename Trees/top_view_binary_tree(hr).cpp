
#include<vector>
#include<map>
#include<set>
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
map<int,map<int,set<int>>> mymap;
    void solve(Node *curr,int col,int row)
    {
        if(!curr)
            return;
        
        mymap[col][row].insert(curr->data);
        solve(curr->left,col-1,row+1);
        solve(curr->right,col+1,row+1);
    }
    
    vector<vector<int>> verticalTraversal(Node* root) {
        solve(root,0,0);
        
        vector<vector<int>> ans;
        for(auto m1: mymap)
        {    
            ans.push_back(vector<int>());
            for(auto m2: m1.second)
            {
                for(auto m3: m2.second)
                    ans.back().push_back(m3);
            }
        }
        return ans;
    }

    void topView(Node * root) {
        vector<vector<int>> v;
        v = verticalTraversal(root);
        for(int i = 0; i< v.size(); i++)
                cout<<*(v[i]).begin()<<" ";

    }

