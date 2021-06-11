class Solution {
public:
/*
    Connected stones can be reduced to 1 stone,
    the maximum stones can be removed = stones number - islands number.
    so just count the number of "islands".
*/
    vector<int> parent = vector<int>(1000);
    vector<int> sz = vector<int>(1000);
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
    int removeStones(vector<vector<int>>& stones) {
         for(int i = 0; i< 1000; i++)
             make_set(i);
        int groups = stones.size();
        int n = stones.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
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
        
        return stones.size()-groups;
        
    }
};