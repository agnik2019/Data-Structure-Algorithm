using namespace std;
#include<unordered_map>
#include<queue>
#include<vector>
#include<iostream>
class TopologicalSort {
public:
    static vector<int> Toposort(int vertices, const vector<vector<int>>& edges){
        vector<int> sortedorder;
        if(vertices <= 0)
            return sortedorder;
    //initialization
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i< vertices; i++)
        {
            indegree[i] = 0;
            graph[i] = vector<int>();
        }
    //Build the graph
    for(int i = 0; i<edges.size(); i++)
    {
        int parent = edges[i][0], child = edges[i][1];
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
      if(sortedorder.size() != vertices)
        return vector<int>();   
    return sortedorder;
    }
};

int main(){
    vector<int> result = TopologicalSort::Toposort(4,vector<vector<int>>{vector<int>{3,2},
           vector<int>{3,0},
           vector<int>{2,0},
           vector<int>{2,1} });
        for(auto num : result)
            cout<<num<<" ";
}