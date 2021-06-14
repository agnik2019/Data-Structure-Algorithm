using namespace std;
#include<iostream>
#include<vector>
#include<stack>
#define pb push_back
#include<unordered_map>
unordered_map<int, vector<int>> adj,rev;
void DFS1(int i,vector<bool> &visited, stack<int>& st){
    visited[i] = true;
    for(auto j: adj[i])
        if(!visited[j]) DFS1(j,visited,st);
    st.push(i);
}
void reverse(int nodes){
    for(int i = 0; i< nodes; i++)
    {
        for(int j : adj[i])
            rev[j].pb(i);
    }   
}
void DFS2(int i, vector<bool> &visited)
{
    cout<<i<<" ";
    visited[i] = true;
    for(int j : rev[i])
        if(!visited[j]) DFS2(j,visited);
}
void findSCC(int nodes){
    stack<int> st;
    vector<bool> visited(nodes,false);
    for(int i = 0; i<nodes; i++)
        if(!visited[i]) DFS1(i,visited,st);
    reverse(nodes);
    for(int i = 0; i<nodes; i++)
        visited[i] = false;
    cout<<"Strongly components are "<<endl;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!visited[curr])
        {
            DFS2(curr,visited);
            cout<<endl;
        }
    }    
}
int main(){
    int node, edge;
    cin>>node>>edge;
    // vector<vector<int>> graph[edge];
    for(int i = 0; i< edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    findSCC(node);
    return 0;
}