#include<iostream>
#include<vector>
using namespace std;
enum node_states{
    UNVISITED,
    INSTACK,
    VISITED        
};
class Graph
{
    int nodes;
    vector<vector<int>> adjList;
    bool dfs_recursion(int start, vector<node_states>& visited)
    {
        visited[start] = INSTACK;
        for(int u: adjList[start])
        {
            if(visited[u] == INSTACK) return true;
            if(visited[u] == UNVISITED && dfs_recursion(u,visited)) 
                return true;
        }
        visited[start] = VISITED;
        return false;
    }
    public:
    Graph(int n): nodes(n), adjList(n){}
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
    }
    bool hasCycle()
    {
        vector<node_states> visited(nodes, UNVISITED);
        for(int i = 0; i< nodes; i++)
        {
            if(visited[i]==UNVISITED && dfs_recursion(i,visited))
                return true;
        }
        return false;
    }
};
int main()
{
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(0,3);
    G.addEdge(3,4);
    G.addEdge(0,4);
    G.addEdge(4,2);
    cout<< G.hasCycle()<< endl;
    return 0;
}
