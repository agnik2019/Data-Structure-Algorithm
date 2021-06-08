#include<iostream>
#include<vector>
#include <queue>
using namespace std;
const int INF = 1000000000;
vector<vector<int>> graph[1000];
void prims(int nodes){
     priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
     int src = 0; // Taking vertex 0 as source
     int cost = 0;
     vector<int> dist(nodes, INF);
      vector<int> parent(nodes, -1);
       vector<bool> visited(nodes, false);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {
           int u = pq.top().second;
            pq.pop();      
           visited[u] = true;  

            for (auto it : graph[u])
            {

                int v = it[0];
                int weight = it[1];
                cout<<u<<"-->"<<v<<": weight "<<weight<<endl;
                cost+= weight;
                if (visited[v] == false && dist[v] > weight)
                {
                    dist[v] = weight;
                    pq.push(make_pair(dist[v], v));
                    parent[v] = u;
                }
            }
        }
        cout<<"total cost of paths using prim "<<cost<<endl;

}
int main()
{
    //Enter the no od nodes and edges 
    int node, edge;
    cin>>node>>edge;
    // vector<vector<int>> graph[edge];
    for(int i = 0; i< edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    prims(node);
    return 0;
}
