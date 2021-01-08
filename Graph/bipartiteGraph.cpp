class Solution {
public:
    
    bool bipartitehelper(vector<vector<int>> &adj, int startnode,vector<int> &color)
    {
        queue<int> q;

        q.push(startnode);
        color[startnode]=1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto e : adj[curr])
            {
                    //check color
                    //visit other nodes and assign color and add to queue
                if(color[e] == color[curr])
                    return false;
                if(color[e] == -1) //-1 for unvisited
                {
                    color[e]= 1-color[curr]; //1 or 0
                    q.push(e);
                }
            }
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i<graph.size(); i++) //multicomponent
        {
              if(color[i] == -1 && !bipartitehelper(graph, i, color)) return false;
        }
        return true;      
    }
};