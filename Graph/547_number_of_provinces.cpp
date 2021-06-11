class Solution {
public:
    void dfs_helper(unordered_map<int,vector<int>> &mp, int src, vector<bool>& visited)
    {
        visited[src]=true;
        for(auto child: mp[src])
        {
            if(!visited[child]) dfs_helper(mp,child,visited);
        }
    }
    int dfs(unordered_map<int,vector<int>> &mp, int n)
    {
        vector<bool> visited(n,false);
         int component = 0;
        for(int i = 0; i< n; i++)
        {
           if(!visited[i]) 
           {
                dfs_helper(mp,i,visited);
                component++;
            }
        }
        return component;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //1. convert the adjacency matrix to adjacency list
        //2. then implement dfs helper method using start node and then explore children
        //3. run for loop and inside dfs_helper
        unordered_map<int, vector<int>> mp;
        int vertices = isConnected.size();
        for(int i = 0; i< isConnected.size(); i++){
            for(int j = 0; j< isConnected.size(); j++)
            {
                if(isConnected[i][j]) mp[i].push_back(j);
            }
        }
        return dfs(mp, vertices);
        
    }
};