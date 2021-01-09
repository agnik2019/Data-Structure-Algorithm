#include<iostream>
#include<vector>
using namespace std;
class Graph
{
    int nodes;
    vector<vector<int>> adjList;
    void dfs_recursion(int start, vector<bool>& visited)
    {
        visited[start] = true;
        cout<<start<<endl;
        for(int u: adjList[start])
        {
            if(!visited[u]) dfs_recursion(u,visited);
        }
    }
    public:
    Graph(int n): nodes(n), adjList(n){}
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
    }
    void DFS()
    {
        vector<bool> visited(nodes, false);
        for(int i = 0; i< nodes; i++)
        {
            if(!visited[i]) dfs_recursion(i,visited);
        }
    }
};
int main()
{
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(0,3);
    G.addEdge(3,4);
    G.addEdge(4,0);
    G.addEdge(4,2);
    G.DFS();
    return 0;
}
