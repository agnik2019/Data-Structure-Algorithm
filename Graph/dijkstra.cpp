#include<iostream>
#include<vector>
#include <queue>
using namespace std;
const int INF = 1000000000;
vector<vector<int>> graph[1000];
void dijkstra(int src,int nodes)
{
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    vector<int> dist(nodes, INF);
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();      

        for (auto it : graph[u])
        {
           int v = it[0];
           int weight = it[1];
            if (dist[v] > dist[u]+weight)
                {
                    dist[v] = dist[u]+weight;
                    pq.push(make_pair(dist[v], v));
                }
         }
     }
    cout<<"Djkstra single source shortest path "<<endl;
        for(int i=1;i<=nodes;i++)
        {
            if(dist[i] <INF)
              cout<<dist[i]<<" ";
            else cout<<-1<<" ";
        cout<<endl;
        }
}
int main()
{
    //Enter the no od nodes and edges 
    int node, edge,src;
    cin>>node>>edge;
    // vector<vector<int>> graph[edge];
    for(int i = 0; i< edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    cin>>src;
    dijkstra(src,node);
    return 0;
}
