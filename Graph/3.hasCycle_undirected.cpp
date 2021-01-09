#include<iostream>
#include<vector>
using namespace std;
class Graph
{
    int nodes;
    vector<vector<int>> adjList;
    bool hasCycle_recursion(int start, vector<bool>& visited,int parent)
    {
        visited[start] = true;
        for(int u: adjList[start])
        {
            if(visited[u] && u!=parent) return true;
            if(!visited[u] && hasCycle_recursion(u,visited,start)) return true;
        }
        return false;
    }
    public:
    Graph(int n): nodes(n), adjList(n){}
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    bool hasCycle()
    {
        vector<bool> visited(nodes, false);
        for(int i = 0; i< nodes; i++)
        {
            if(!visited[i] && hasCycle_recursion(i,visited,-1)) 
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
    G.addEdge(4,0);
    G.addEdge(4,2);
    cout<<boolalpha<<G.hasCycle()<<endl; //true
    return 0;
}
