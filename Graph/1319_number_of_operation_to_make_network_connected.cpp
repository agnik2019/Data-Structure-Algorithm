class Solution {
public:
    const int N = 1e5;
    vector<int> parent = vector<int>(N);
    vector<int> sz = vector<int>(N);
    void makeset(int i)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    int find_set(int v)
    {
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int u,int v){
        int a = find_set(u);
        int b = find_set(v);
        if(a!=b){
            if(sz[a]<sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a]+=sz[b];
        }
            
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        for(int i = 0; i<N; i++)
            makeset(i);
        int groups = n;
        for(int i = 0; i< connections.size(); i++)
        {
            int x = find_set(connections[i][0]);
            int y = find_set(connections[i][1]);
            if(x!=y){
                groups--;
                union_set(x,y);
            }
        }
        return groups-1;
    }
};