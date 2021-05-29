class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        vector<int> sortedorder;
        if(numCourses <= 0)
            return sortedorder;
    //initialization
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i< numCourses; i++)
        {
            indegree[i] = 0;
            graph[i] = vector<int>();
        }
    //Build the graph
    for(int i = 0; i<edges.size(); i++)
    {
        int child = edges[i][0], parent = edges[i][1];
        graph[parent].push_back(child);
        indegree[child]++;
    }
    queue<int> q;
    for (auto i: indegree){
        if(i.second == 0)
            q.push(i.first);
    }
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        sortedorder.push_back(vertex);
        vector<int> children= graph[vertex];
        for(auto child: children)
        {
            indegree[child]--;
            if(indegree[child] == 0)
                q.push(child);
        }
    }
      if (sortedorder.size() != numCourses)
          return vector<int>();  
       return sortedorder;
        
    }
};