class Solution {
public:
    vector<int> parent = vector<int>(200);
    vector<int> sz = vector<int>(200);
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
    int findCircleNum(vector<vector<int>>& M) {
        for(int i = 0; i< 200; i++)
             make_set(i);
        int groups = M.size();
        for(int i = 0; i<M.size(); i++)
        {
            for(int j= 0; j<M.size(); j++)
            {
                if(M[i][j]){
                    int u = find_set(i);
                    int v = find_set(j);
                    if(u!=v)
                    {
                        groups--;
                        union_set(u,v);
                    }
                }
            }
        }
        
        return groups;
    }
};