#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Graph
{
    int nodes;
    vector<vector<int>> adjList;
    void TS_recursion(int start, vector<bool>& visited, stack<int>& st)
    {
        visited[start] = true;
        for(int u: adjList[start])
        {
            if(!visited[u]) TS_recursion(u,visited,st);
        }
        st.push(start);
    }
    public:
    Graph(int n): nodes(n), adjList(n){}
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
    }
    void topologicalSort()
    {
        vector<bool> visited(nodes, false);
        stack<int> st;
        for(int i = 0; i< nodes; i++)
        {
            if(!visited[i]) TS_recursion(i,visited,st);
        }
        while(!st.empty())
         {
             cout<<st.top()<<" ";
             st.pop();
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
    G.topologicalSort();
    return 0;
}
