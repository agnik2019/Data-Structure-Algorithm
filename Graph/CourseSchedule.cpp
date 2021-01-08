class Solution {
public:
    bool dfs(int s,vector<int> & visited,vector<vector<int>>& adjList)
    {
        visited[s] = 1;
        for(int u: adjList[s])
        {
            if(visited[u]==1) return true;
            if(visited[u]==0 && dfs(u,visited,adjList))
                return true;
        }
        visited[s]=2;
        return false;
        
    }
     
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto pre : prerequisites)
                 adjList[pre[0]].push_back(pre[1]);
        vector<int> visited(numCourses, 0);
        for(int i = 0; i<numCourses; i++)
        {
            if(visited[i] == 0 && dfs(i,visited,adjList))
                return false; //cycle contains --> true so can finish -> false
        } 
    return true;     
        
    }
};