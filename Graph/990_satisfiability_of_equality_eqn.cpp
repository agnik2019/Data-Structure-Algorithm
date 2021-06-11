class Solution {
public:
    vector<int> parent= vector<int>(26);
    vector<int> sz = vector<int>(26);
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
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i<26; i++)
            make_set(i);
        for(auto eqn: equations)
        {
            int x = eqn[0]-'a';
            int y = eqn[3]-'a';
            if(eqn[1] == '=')
                union_set(x,y);
        }
        for(auto eqn: equations)
        {
            int x = find_set(eqn[0]-'a');
            int y = find_set(eqn[3]-'a');
            if(eqn[1] == '!')
                if(x==y) return false;;
        }
        return true;
    }
};