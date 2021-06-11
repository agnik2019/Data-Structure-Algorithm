class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& connections,int start,vector<bool> &visited)
    {
        if(visited[start]) return;
        visited[start] = true;
        for(auto child:connections[start])
            if(!visited[child]) dfs(connections,child,visited);
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        unordered_map<int,vector<int>> graph;
          vector<bool> visited(n,false);
        int components = 0;
        for(auto e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(int i=0; i< n; i++){
            if(!visited[i]){
            dfs(graph,i,visited);
            components++;
            }
        }
        return components-1;
    }
};