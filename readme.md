# Data Structures & Algorithms

In this repo, some important data structure and algorithmic questions from leetcode, gfg, interviewbit, hackerrank and cses problem set is posted. 
The questions cover all possible types of problems.

### Definition:
Asymptotic Notation is the hardware independent notation used to tell the time and space complexity of an algorithm. Meaning it's a standardized way of measuring how much memory an algorithm uses or how long it runs for given an input.

#### Complexities
The following are the Asymptotic rates of growth from best to worst:
- constant growth - ``O(1)`` Runtime is constant and does not grow with `n`
- logarithmic growth – ``O(log n)`` Runtime grows logarithmically in proportion to `n`
- linear growth – ``O(n)`` Runtime grows directly in proportion to `n`
- superlinear growth – ``O(n log n)`` Runtime grows in proportion _and_ logarithmically to `n`
- polynomial growth – `O(n^c)` Runtime grows quicker than previous all based on `n`
- exponential growth – `O(c^n)` Runtime grows even faster than polynomial growth based on `n`
- factorial growth – `O(n!)` Runtime grows the fastest and becomes quickly unusable for even
small values of `n`

[(source: Soumyadeep Debnath, _Analysis of Algorithms | Big-O analysis_)](https://www.geeksforgeeks.org/analysis-algorithms-big-o-analysis/)

Visualized below; the x-axis representing input size and the y-axis representing complexity:

![#](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7e/Comparison_computational_complexity.svg/400px-Comparison_computational_complexity.svg.png)

[(source: Wikipedia, _Computational Complexity of Mathematical Operations_)](https://en.wikipedia.org/wiki/Computational_complexity_of_mathematical_operations)

#### Big-O notation
Big-O refers to the upper bound of time or space complexity of an algorithm, meaning it worst case runtime scenario. An easy way to think of it is that runtime could be better than Big-O but it will never be worse.
#### Big-Ω (Big-Omega) notation
Big-Omega refers to the lower bound of time or space complexity of an algorithm, meaning it is the best runtime scenario. Or runtime could worse than Big-Omega, but it will never be better.
#### Big-θ (Big-Theta) notation
Big-Theta refers to the tight bound of time or space complexity of an algorithm. Another way to think of it is the intersection of Big-O and Big-Omega, or more simply runtime is guaranteed to be a given complexity, such as `n log n`.

#### What you need to know
- Big-O and Big-Theta are the most common and helpful notations
- Big-O does _not_ mean Worst Case Scenario, Big-Theta does _not_ mean average case, and Big-Omega does _not_ mean Best Case Scenario. They only connote the algorithm's performance for a particular scenario, and all three can be used for any scenario.
- Worst Case means given an unideal input, Average Case means given a typical input, Best case means a ideal input. Ex. Worst case means given an input the algorithm performs particularly bad, or best case an already sorted array for a sorting algorithm.
- Best Case and Big Omega are generally not helpful since Best Cases are rare in the real world and lower bound might be very different than an upper bound.
- Big-O isn't everything. On paper merge sort is faster than quick sort, but in practice quick sort is superior.

![bigo](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/big0.jpg)
![bigo2](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/bigo2.jpg)
![master](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/master.jpg)
![recur](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/recur.jpg)




# Sorting Techniques

**Selection Sort**: 
#### Definition
- A comparison based sorting algorithm.
  - Starts with the cursor on the left, iterating left to right
  - Compares the left side to the right, looking for the smallest known item
    - If the left is smaller than the item to the right it continues iterating
    - If the left is bigger than the item to the right, the item on the right becomes the known smallest number
    - Once it has checked all items, it moves the known smallest to the cursor and advances the cursor to the right and starts over
  - As the algorithm processes the data set, it builds a fully sorted left side of the data until the entire data set is sorted
- Changes the array in place.

#### What you need to know
- Inefficient for large data sets.
- Very simple to implement.

#### Time Complexity
- Best Case Sort: `O(n^2)`
- Average Case Sort: `O(n^2)`
- Worst Case Sort: `O(n^2)`

#### Space Complexity
- Worst Case: `O(1)`

#### Visualization
![#](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)

[(source: Wikipedia, _Insertion Sort_)](https://en.wikipedia.org/wiki/Selection_sort)
### Find the element in unsorted array and swap it with element at beginning.
```cpp
 for(int i=0; i<n-1; i++)
    {
        for(int j= i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
                swap(arr[j],arr[i]);
        }
    }
```

**Bubble Sort**
Repeatedly swap two adjacent elements if they are in wrong order.
```cpp
    for(int counter = 1; counter<n; counter++)
    {
        for(int i = 0; i<n-counter; i++)
        {
            if(arr[i]>arr[i+1])
                swap(arr[i], arr[i+1]);        
        }
    }
```

**Insertion Sort**
#### Definition
- A comparison based sorting algorithm.
  - Iterates left to right comparing the current cursor to the previous item.
  - If the cursor is smaller than the item on the left it swaps positions and the cursor compares itself again to the left hand side until it is put in its sorted position.
  - As the algorithm processes the data set, the left side becomes increasingly sorted until it is fully sorted.
- Changes the array in place.

#### What you need to know
- Inefficient for large data sets, but can be faster for than other algorithms for small ones.
- Although it has an `O(n^2)` time complexity, in practice it is slightly less since its comparison scheme only requires checking place if it is smaller than its neighbor.

#### Time Complexity
- Best Case: `O(n)`
- Average Case: `O(n^2)`
- Worst Case: `O(n^2)`

#### Space Complexity
- Worst Case: `O(n)`

#### Visualization
![#](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

[(source: Wikipedia, _Insertion Sort_)](https://en.wikipedia.org/wiki/Insertion_sort)

### Insert an element from unsorted array to its correct position in sorted array.
```cpp
    for(int i = 1; i<n; i++)
    {
        int current = arr[i];
        int j = i-1;
        while(arr[j]> current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
```

**Merge Sort**
#### Definition
- A divide and conquer algorithm.
  - Recursively divides entire array by half into subsets until the subset is one, the base case.
  - Once the base case is reached results are returned and sorted ascending left to right.
  - Recursive calls are returned and the sorts double in size until the entire array is sorted.

#### What you need to know
- This is one of the fundamental sorting algorithms.
- Know that it divides all the data into as small possible sets then compares them.

#### Time Complexity
- Worst Case: `O(n log n)`
- Average Case: `O(n log n)`
- Best Case: `O(n)`

#### Space Complexity
- Worst Case: `O(1)`

#### Visualization
![#](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/Merge_sort_algorithm_diagram.svg/400px-Merge_sort_algorithm_diagram.svg.png)

[(source: Wikipedia, _Merge Sort_)](https://en.wikipedia.org/wiki/Merge_sort)
```cpp
	void merge(vector<int>& nums, int l, int m, int r){
        vector<int> tmp(r - l + 1);
        int i = l; // index for left subarray
        int j = m + 1; // index for right subarray
        int k = 0; // index for temporary array
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
            else tmp[k++] = nums[j++];
        }
        while(i <= m) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++]; 
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
    }
	
	// mergeSort(nums, 0, nums.size() - 1);
    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int m = l + (r - l) / 2; //middle index, same as (l+r)/2
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
```

**Quick Sort**
#### Definition
- A divide and conquer algorithm
  - Partitions entire data set in half by selecting a random pivot element and putting all smaller elements to the left of the element and larger ones to the right.
  - It repeats this process on the left side until it is comparing only two elements at which point the left side is sorted.
  - When the left side is finished sorting it performs the same operation on the right side.
- Computer architecture favors the quicksort process.
- Changes the array in place.

#### What you need to know
- While it has the same Big O as (or worse in some cases) many other sorting algorithms it is often faster in practice than many other sorting algorithms, such as merge sort.

#### Time Complexity
- Worst Case: `O(n^2)`
- Average Case: `O(n log n)`
- Best Case: `O(n log n)`

#### Space Complexity
- Worst Case: `O(log n)`

#### Visualization
![#](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

[(source: Wikipedia, _Quicksort_)](https://en.wikipedia.org/wiki/Quicksort)

#### Merge Sort Vs. Quicksort
- Quicksort is likely faster in practice, but merge sort is faster on paper.
- Merge Sort divides the set into the smallest possible groups immediately then reconstructs the incrementally as it sorts the groupings.
- Quicksort continually partitions the data set by a pivot, until the set is recursively sorted.
```cpp
    int partitionIndex(vector<int>& nums, int low, int high){
        int index = low-1;
        for (int j=low;j<=high;j++){
            if (nums[j]<= nums[high]){
                index++;
                swap(nums[index], nums[j]);
            }
        }
        return index;
    }
```
Here we choose the pivot element as last element of array. But sometimes it gives worst time complexity.
So its better to choose random pivot element to improve time complexity.
```cpp
    int partitionIndex(vector<int>& nums, int low, int high){
        int randIndex = low + rand()%(high-low+1);
        swap(nums[randIndex], nums[high]);
        int index = low-1;
        for (int j=low;j<=high;j++){
            if (nums[j]<= nums[high]){
                index++;
                swap(nums[index], nums[j]);
            }
        }
        return index;
    }
    void quickSortHelper(vector<int>& nums, int low, int high){
        if (low<high){
            int p = partitionIndex(nums, low, high);
            quickSortHelper(nums, low, p-1);
            quickSortHelper(nums, p+1, high);
        }
    }
```
# HeapSort

#### Heap

A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:

- 1. Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
- 2. Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
![heap](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/heapsort2.gif)

#### Visualization
![#](https://upload.wikimedia.org/wikipedia/commons/f/fe/Heap_sort_example.gif)
```cpp
    void siftDown(vector<int>& nums, int n, int i){
        int biggest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if(l < n && nums[biggest] < nums[l])
            biggest = l;
        if(r < n && nums[biggest] < nums[r])
            biggest = r;
        if(biggest != i){
            swap(nums[i], nums[biggest]);
            siftDown(nums, n, biggest);
        }
    }
    
	// heapSort(nums);
    void heapSort(vector<int>& nums){
        // heapify stage (bottom up approach)
        for(int i = nums.size() / 2 - 1; i >= 0; i--)
            siftDown(nums, nums.size(), i);
        // sorting stage
        for(int i = nums.size() - 1; i > 0; i--){
            swap(nums[0], nums[i]);
            siftDown(nums, i, 0);
        }
    }
```
## Heap

**Problem Patterns where HEAP is used**
HEAP is common data structure to use can be categorized in following 4 categories:

- Top K Pattern
- Merge K Sorted Pattern
- Two Heaps Pattern
- Minimum Number Pattern

All questions under one patterns has some similarities in terms of using HEAP as a data structure. Completing these questions would gurantee you mastery on the HEAP data structure. Below list includes some of the most common questions asked in most of the companies.

**Top K Pattern**
- LC #215 - Kth largest number in an array
- LC #973 - K closest points to origin
- LC #347 - Top k frequent elements/numbers
- LC #692 - Top k frequent words
- LC #264 - Ugly Number II
- LC #451 - Frequency Sort
- LC #703 - Kth largest number in a stream
- LC #719 - Kth smallest distance among all pairs
- LC #767 - Reorganize String
- LC #358 - Rearrange string K distance apart
- LC #1439 - Kth smallest sum of a matrix with sorted rows

**Merge K sorted pattern**
- LC #23 - Merge K sorted
- LC #373 - K pairs with the smallest sum
- LC #378 - K smallest numbers in M-sorted lists

**Two Heaps Pattern**
- LC #295 - Find median from a data stream
- LC #480 - Sliding window Median
- LC #502 - Maximize Capital/IPO

**Minimum number Pattern**
- LC #1167 - Minimum Cost to connect sticks/ropes
- LC #253 - Meeting Rooms II
- LC #759 - Employee free time
- LC #857 - Minimumcost to hire K workers
- LC #621 - Minimum number of CPU (Task scheduler)
- LC #871 - Minimum number of Refueling stops


## Bitmasks
* Bitmasking is a technique used to perform operations at the bit level. Leveraging bitmasks often leads to faster runtime complexity and
  helps limit memory usage
* Test kth bit: `s & (1 << k);`
* Set kth bit: `s |= (1 << k);`
* Turn off kth bit: `s &= ~(1 << k);`
* Toggle kth bit: `s ^= (1 << k);`
* Multiple by 2<sup>n</sup>: `s << n;`
* Divide by 2<sup>n</sup>: `s >> n;`
* Intersection: `s & t;`
* Union: `s | t;`
* Set Subtraction: `s & ~t;`
* Extract lowest set bit: `s & (-s);`
* Extract lowest unset bit: `~s & (s + 1);`
* Swap Values:
             ```
                x ^= y;
                y ^= x;
                x ^= y;
             ```


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
![krush](https://upload.wikimedia.org/wikipedia/commons/a/a3/UnionFindKruskalDemo.gif)
```cpp
int main()
{
    bool cycle;
    for(int i = 0; i< N; i++)
        make_set(i);
    int n, m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0; i<m; i++)
    {
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto i: edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x==y)
            continue;
        else {
            cout<<u<<" "<<v<<endl;
            cost += w;
            union_set(u,v);
        }
    }
    if(cycle) cout<<"cycle is found ";
    else cout<<"cycle not found"<<endl;
    return 0;
}
```
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
## Prims Algorithm
We use a boolean array visited[] to represent the set of vertices included in MST. If a value visited[v] is true, then vertex v is included in MST, otherwise not. Array dist[] is used to store key/distance values of all vertices. Another array parent[] to store indexes of parent nodes in MST. The parent array is the output array which is used to show the constructed MST.



![prim](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/prim.gif)

```cpp
const int INF = 1000000000;
vector<vector<int>> graph[1000];
void prims(int nodes){
     priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
                // pair indicates <weight,node>
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
```

## Dijkstra Algorithm
![dj](https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif)
Lets visualize with the help of a table
![dj1](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/dj1.jpg)
![dj2](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/dj2.jpg)


```cpp
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
```

# Pattern Matching

**BruteForce Solution**
```cpp
int strStr(const string A, const string B) 
{
    int m=A.length(),n=B.length();

    for(int i=0;i<=m-n;i++)
    {   
        int j=0;
        for(;j<n;j++)
            if(B[j]!=A[i+j])break;
        
        if(j==n) return i;
    }
    return -1;
}
```

## KMP Algo
![kmp](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/kmp1.jpg)

```cpp
vector<int> prefix_fun(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i = 1; i<s.size(); i++){
        int j= pi[i-1];
        while(j>0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int kmpalgo(string text, string pat){
    int pos = -1;
    int i(0),j(0);
    vector<int> pi = prefix_fun(pat);
    while(i< text.length()){
        if(text[i] == pat[j]){
            i++; 
            j++;
        }
        else{
            if(j) j = pi[j-1];
            else i++;
        }
        if(j == pat.length()){
            pos = i-pat.length();
            break;
        }
    }
    return pos;
}
```


## Boyer Moore's algorithm
![boyer](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/boyer.jpg)

```cpp
void fillHashTable(string s,int hashtable[256])
    {
        for(int i = 0; i< 256; i++)
            hashtable[i] = -1;
        for(int i = 0; i< s.length(); i++)
            hashtable[(int)s[i]] = i;
    }
int strStr(string haystack, string needle) {
        int S = needle.length();
        int T = haystack.length();
        int i = 0;
        int hashtable[256];
        fillHashTable(haystack,hashtable);
        while( i<= (T-S))  //n-m
        {
            int j = S-1;
            while(j >= 0 && needle[j] == haystack[i+j])
                j--;
            if(j<0)
            {
                return i;
                i += (i+S < T) ? S-hashtable[haystack[i+S]]:1;
            } 
            else
                i += max(1, j-hashtable[haystack[i+j]]);
        }
        return -1;
    }
```

## Rabin Karp String algorithm
![rolling](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/rolling.jpg)
![rolling2](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/rolling2.jpg)
```cpp
int p = 31;
const int N = 1e5+7, mod = 1e9+7;
vector<long long> power(N);
int main(){

    string t = "agniksahannik";
    string s = "nik";
    int T = t.size(), S= s.size();
    power[0] = 1;
    for(int i = 1; i<N; i++)
        power[i] = (power[i-1]*p)%mod;

    vector<long long> h(T+1,0);
    for(int i = 0; i<T;i++)
        h[i+1] = (h[i]+(t[i]-'a'+1)*power[i])%mod;
    long long h_s = 0;
    for(int i = 0; i<S; i++)
        h_s = (h_s+(s[i]-'a'+1)*power[i])%mod;

    for(int i = 0; i+S-1<T; i++)
    {
        long long cur_hash = (h[i+S]-h[i]+mod)%mod;
        if(cur_hash == (h_s*power[i])%mod)
            cout<<i<<" ";
    }
    return 0;
}
```
# Backtracking
For understanding backtracking algorithm, we need to understand the concept of recursion. For understanding recursion to build the base of backtracking, we will see the example given below:
**Write a recursive function printAllBinary that accepts an integer number of digits and prints all binary numbers that have exactly that many digits, in ascending order, one per line**
eg: printAllBinary(3):
    000
    001
    010
    011
    100
    101
    110
    111
![bt](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/backtrack1.jpg)

```cpp
void printAllBinaryHelper(int digit, string sofar){
    if(digit == 0)
        cout<<sofar<<endl;
    else{
        printAllBinaryHelper(digit-1, sofar+"0");
        printAllBinaryHelper(digit-1, sofar+"1");
    }
}
void printAllBinary(int numDigits)
{
    printAllBinaryHelper(numDigits,"");
}
```
**Recursive Backtracking**: 
using recursion to explore solutions to a problem and abandoning them if they are not suitable.
– Determine whether a solution exists
– Find a solution
– Find the best solution
– Count the number of solutions
– Print/find all the solutions
**Applications**:
– Puzzle solving (Sudoku, Crosswords, etc.)
– Game playing (Chess, Solitaire, etc.)
– Constraint satisfaction problems (scheduling, matching, etc.)

**Recursion Checklist**
- Find what information we need to keep track of. What inputs/outputs are needed to solve the problem at each step? Do we need a wrapper function?
- Find our base case(s). What are the simplest (nonrecursive) instance(s) of this problem?
- Find our recursive step. How can this problem be solved in terms of one or more simpler instances of the same problem that lead to a base case?
- Ensure every input is handled. Do we cover all possible cases? Do we need to handle errors?


Write a recursive function diceRoll that accepts an integer representing a number of 6-sided dice to roll, and output all possible combinations of values that could appear on the dice.

![bt2](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/backtrack2.jpg)

Enter the available dice numbers 2
[1 1 ][1 2 ][1 3 ][1 4 ][1 5 ][1 6 ][2 1 ][2 2 ][2 3 ][2 4 ][2 5 ][2 6 ][3 1 ][3 2 ][3 3 ][3 4 ][3 5 ][3 6 ][4 1 ][4 2 ][4 3 ][4 4 ][4 5 ][4 6 ][5 1 ][5 2 ][5 3 ][5 4 ][5 5 ][5 6 ][6 1 ][6 2 ][6 3 ][6 4 ][6 5 ][6 6 ]

```cpp
void diceRollHelper(int dice, vector<int>& chosen) 
{
    if (dice == 0) 
    {
        cout<<'[';
        for(auto num: chosen)
         cout<< num<< " "; // base case
        cout<<']';
    } 
    else 
    {
        for (int i = 1; i <= 6; i++) 
        {
            chosen.push_back(i); // choose
            diceRollHelper(dice - 1, chosen); // explore
            chosen.pop_back(); // un-choose
        }
    }
}
// Prints all possible outcomes of rolling the given
// number of six-sided dice in {#, #, #} format.
void diceRolls(int dice) 
{
    vector<int> chosen;
    diceRollHelper(dice, chosen);
}
```

**Write a function diceSum similar to diceRoll, but it also accepts a desired sum and prints only combinations that add up to exactly that sum.**
```
diceSum(2,7) 
{1,6}
{2,5}
{3,4}
{4,3}
{5,2}
{6,1}
```
```cpp
void diceSum(int dice, int desiredSum) 
{
    Vector<int> chosen;
    diceSumHelper(dice, desiredSum, chosen);
}
void diceSumHelper(int dice, int desiredSum, Vector<int>& chosen) 
{
    if (dice == 0) 
    {
        if (sumAll(chosen) == desiredSum) 
        {
             cout << chosen << endl; // base case
        }
    } 
    else 
    {
        for (int i = 1; i <= 6; i++) 
        {
            chosen.add(i); // choose
            diceSumHelper(dice - 1, desiredSum, chosen); // explore
            chosen.remove(chosen.size() - 1); // un-choose
        }
    }
}
int sumAll(const Vector<int>& v)
{
    int sum = 0;
    for (int k : v) { sum += k; }
    return sum;
}
```
### We need not visit every branch of the decision tree.
- Some branches are clearly not going to lead to success.
- We can preemptively stop, or prune, these branches
```cpp
void diceSum(int dice, int desiredSum) 
{
    Vector<int> chosen;
    diceSumHelper(dice, 0, desiredSum, chosen);
}
void diceSumHelper(int dice, int sum, int desiredSum, Vector<int>& chosen)
{
    if (dice == 0) 
    {
        if (sum == desiredSum) {
        cout << chosen << endl; // base case
        }
    } 
    else if (sum + 1*dice <= desiredSum && sum + 6*dice >= desiredSum) 
    {
        for (int i = 1; i <= 6; i++) 
        {
            chosen.add(i); // choose
            diceSumHelper(dice - 1, sum + i, desiredSum, chosen); // explore
            chosen.remove(chosen.size() - 1); // un-choose
        }
    }
}
```
### Choose-explore-unchoose pattern
For each option
 - Choose the option.
 - Explore the option.
 - Unchoose the option.

```cpp
void explore(options, soFar)
{
    if (no more decisions to make) {
        // base case
    } else {
        // recursive case, we have a decision to make
        for (each available option) {
            choose (update options/sofar)
            explore (recur on updated options/sofar)
            unchoose (undo changes to options/sofar)
        }
    }
}
```
### N QUEENS PROBLEM
![bt3](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/backtrack4.jpg)
![bt4](https://github.com/agnik2019/Data-Structure-Algorithm/blob/main/assets/backtrack3.png)
```cpp
    bool place(vector<string> &board,int row, int col)
    {
        int i,j;
        int n = board.size();
        for(int i = 0; i< col; i++)
            if(board[row][i]=='Q') return false;
        //check left sided diagonal
        for(int i = row, j = col; i<n && j>=0; i++,j--)
            if(board[i][j]=='Q') return false;
        //check right sided diagonal
        for(int i = row, j = col; i>=0 && j>=0; i--,j--)
            if(board[i][j]=='Q') return false;
        
        return true;
    }
    void solve(vector<string> &board,int col,int n)
    {
        if(col == n)
        {
            sol.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++)
        {
            if(place(board,row,col))
            {
                board[row][col] ='Q';   // choose
                solve(board,col+1,n);   // explore
                board[row][col]='.';    // unchoose
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0,n);
        return sol;
    }
```



# Dynamic Programming
Some popular problems of dynamic programming are given in the table below:
## Dynamic Programming
| **ID** | **PROBLEM STATEMENT**                                | **PROBLEM LINK**                        |
|--------|------------------------------------------------------|-----------------------------------------|
| 1     | Climbing Stairs                                      | [LeetCode](https://leetcode.com/problems/climbing-stairs/)                                                          |
| 2     | Coin Sum Infinite                                    | [InterviewBit](https://www.interviewbit.com/problems/coin-sum-infinite/)                                                |
| 3     | Min Cost Climbing Stairs                             | [LeetCode](https://leetcode.com/problems/min-cost-climbing-stairs/)                                                 |
| 4      | Rod Cutting Problem                                  | [GFG](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)                                                      |
| 5      | Longest Common Subsequence                           | [LeetCode](https://leetcode.com/problems/delete-operation-for-two-strings/)                                         |
| 6      | Print Longest Common Subsequence                     | [Hackerrank](https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem)|
| 7      | Longest Increasing Subsequence                       | [LeetCode](https://leetcode.com/problems/longest-increasing-subsequence/) , [InterviewBit](https://www.interviewbit.com/problems/longest-increasing-subsequence/)                                    |
| 8     | Edit Distance                                        |   [LeetCode](https://leetcode.com/problems/edit-distance/)                                                             |
| 9     |   Longest Common Substring                           | [LeetCode](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)                                       |
| 10     | Maximum Sum Contiguous Subarray                      | [LeetCode](https://leetcode.com/problems/maximum-subarray/)                                                          |
| 11     | Maximum Sum without adjacent Element(House Robber)   |   [LeetCode](https://leetcode.com/problems/house-robber/)                                                              |
| 12     | Maximum Product Subarray                             | [LeetCode](https://leetcode.com/problems/maximum-product-subarray/)                                                  |
| 13      | Find minimum number of coins that make a given value |   [LeetCode](https://leetcode.com/problems/coin-change/)                                                               |
| 14      | Min Cost Path                                        | [InterviewBit](https://www.interviewbit.com/problems/min-sum-path-in-matrix/ )                                           |
| 15      | Maximal Rectangle                                    | [LeetCode](https://leetcode.com/problems/maximal-rectangle/) , [InterviewBit](https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/)                                    |
| 16     | Minimum Jump to reach End                            |   [LeetCode](https://leetcode.com/problems/jump-game-ii/) ,      [InterviewBit](https://www.interviewbit.com/problems/min-jumps-array/)                                                   |
| 17     | 0 - 1 Knapsack Problem                               | [GFG](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0)                                       |
| 18     | Partition Equal Subset Sum                           | [LeetCode](https://leetcode.com/problems/partition-equal-subset-sum/)                                                |
| 19     | Longest Palindromic Subsequence                      | [LeetCode](https://leetcode.com/problems/longest-palindromic-subsequence/)                                           |
| 20      | Longest Bitonic Subsequence                          | [InterviewBit](https://www.interviewbit.com/problems/length-of-longest-subsequence/)                                     |
| 21     | Word Break                                           |      [LeetCode](https://leetcode.com/problems/word-break/) ,              [InterviewBit](https://www.interviewbit.com/problems/word-break/)                                                        |
| 22     | Interleaving String                                  | [LeetCode](https://leetcode.com/problems/interleaving-string/) , [InterviewBit](https://www.interviewbit.com/problems/interleaving-strings/)                                              |
| 23     | Matrix Chain Multiplication                          | [LeetCode](https://leetcode.com/problems/burst-balloons/)                                                            |
| 24     | Palindrome Partitioning                              | [LeetCode](https://leetcode.com/problems/palindrome-partitioning-ii/)                                                |





