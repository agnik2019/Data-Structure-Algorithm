const int N = 2000;
class Solution {
public:  
    vector<int> parent{vector<int>(2000)};
    vector<int> sz{vector<int>(2000)};
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        for(int i = 0; i< 2000; i++)
             make_set(i);
        for(auto i: edges)
        {
            int u = i[0];
            int v = i[1];
            int x = find_set(u);
            int y = find_set(v);
            if(x==y){
              res.push_back(u);
              res.push_back(v);
            }
            else 
                union_set(u,v);
        }
        return res;
        
    }
};