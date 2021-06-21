class NumArray {
public:
     vector<int> tree;
    vector<int> a;
    void build(int node, int st, int en)
    {
        if(st == en)
        {
            tree[node] = a[st];
            return;
        }
        int mid = (st+en)/2;
        build(2*node, st,mid);
        build(2*node+1,mid+1,en);

        tree[node] = tree[2*node]+tree[2*node+1];
    }
    
     void updater(int index, int update_left , int update_right, int node_left , int node_right, int val) 
    {
        if(update_left > node_right || update_right < node_left)    return;     // completely excluded
        if(node_left == node_right)                                             // reached leaf node 
        { 
            tree[index] = val; 
            a[node_left] = val;         // this line can be skipped, we dont give a fuck to vector a once tree has been made
            return; 
        };
        int mid = (node_left + node_right)/2;                                       
        updater(index*2 , update_left , update_right , node_left , mid       , val);
        updater(index*2+1,update_left , update_right , mid+1     , node_right, val);
        tree[index] = tree[index*2] + tree[index*2+1];
        return;
    }
    int query(int node, int st, int en, int l, int r)
    {
        if(st>r || en<l)
            return 0;
        if(l <= st && en <= r)
            return tree[node];
        int mid = (st+en) /2;

        int q1 = query(2*node, st, mid, l, r);
        int q2 = query(2*node+1,mid+1,en,l,r);

        return q1+q2;
    }
    NumArray(vector<int>& arr) {
        int n = arr.size();                                                     
        tree = vector<int> (4*n+1); 
        a = vector<int>(arr.begin() , arr.end());                              
        build(1,0,n-1);  
        
    }
    
    void update(int i, int val) {
        updater(1,i,i,0,a.size()-1 , val);      
    }
    
    int sumRange(int left, int right) {
        return query(1,0,a.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */