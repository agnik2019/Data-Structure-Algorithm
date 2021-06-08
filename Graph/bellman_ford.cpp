#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>
using namespace std;
const int INF = 1000000000;

void bellman_ford(vector<vector<int>> &graph, int src,int nodes)
{
    vector<int> dist(nodes, INF);
    dist[src] = 0;
    for(int i = 0; i<nodes-1; i++)
    {
        for (auto it : graph)
        {
           int u = it[0]; 
           int v = it[1];
           int w = it[2];
           dist[v] = min(dist[v], w+dist[u]);
         }
     }
    cout<<"bellman ford single source shortest path "<<endl;
        for(auto i : dist)
        {
           cout<<i<<" ";
        }
}
int main()
{
    //Enter the no od nodes and edges 
    int node, edge,src;
    cin>>node>>edge;
    vector<vector<int>> graph;
    for(int i = 0; i< edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back({u,v,w});
    }
    cin>>src;
    bellman_ford(graph,src,node);
    return 0;
}
