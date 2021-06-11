# Interview Preparation

In this repo, some important data structure and algorithmic questions from leetcode, gfg, interviewbit, hackerrank and cses problem set is posted. 
The questions cover all possible types of problems.



# Graph

There are several types of problems in graph
- **Union Find**

    - https://leetcode.com/problems/friend-circles/
    - https://leetcode.com/problems/redundant-connection/
    - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
    - https://leetcode.com/problems/number-of-operations-to-make-network-connected/
    - https://leetcode.com/problems/satisfiability-of-equality-equations/
    - https://leetcode.com/problems/accounts-merge/
Main points regarding disjoint set
1. Initialization:
    I will make of node a parent of size 1
2. Union-set
    - Find parent of each node
    - If the parents of each node is not same, update their parent and size
    - Updation will be like this
    ```
        parent[b] = a;
        sz[a] += sz[b];
    ```
3. Find parent
For finding parent we can use eith iterative or recursive method.
Recurance relation will be:
parent[v] = find_set(parent[v]); until finding the actual parent



![princeton](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/quick-union.png)

Code is given below:

```cpp
const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(sz[a] < sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    } 
}
```
Union find algorithm is used for detecting cycles and also in krushkal's algorithm.
```cpp
for(auto i: adjList)
        {
            int u = i[0];
            int v = i[1];
            int x = find_set(u);
            int y = find_set(v);
            if(x==y){ 
               //cycle found
              cycledEdge.push_back(u);
              cycledEdge.push_back(v);
            }
            else 
                union_set(u,v);
        }
```
- DFS Pattern
```cpp
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
    void DFS()
    {
        vector<bool> visited(nodes, false);
        for(int i = 0; i< nodes; i++)
        {
            if(!visited[i]) dfs_recursion(i,visited);
        }
    }
    
```

find cycle usinfg dfs in directed graph
```cpp
enum node_states{
    UNVISITED,  
    INSTACK,
    VISITED        
};
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
```

find cycle usinfg dfs in an undirected graph
```cpp
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
```
TopoLogical sort using dfs
```cpp
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
```


- Kahn's Algorithm

a. Initialization

We will store the graph in Adjacency Lists, which means each parent vertex will have a list containing all of its children. We will do this using a HashMap where the ‘key’ will be the parent vertex number and the value will be a List containing children vertices.
To find the sources, we will keep a HashMap to count the in-degrees i.e., count of incoming edges of each vertex. Any vertex with ‘0’ in-degree will be a source.
b. Build the graph and find in-degrees of all vertices

We will build the graph from the input and populate the in-degrees HashMap.
c. Find all sources

All vertices with ‘0’ in-degrees will be our sources and we will store them in a Queue.
d. Sort

For each source, do the following things:
Add it to the sorted list.
Get all of its children from the graph.
Decrement the in-degree of each child by 1.
If a child’s in-degree becomes ‘0’, add it to the sources Queue.
Repeat step 1, until the source Queue is empty.

```cpp
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
```
