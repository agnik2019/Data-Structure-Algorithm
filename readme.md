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

```
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
``` 
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
