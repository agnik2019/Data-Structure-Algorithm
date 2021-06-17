int Solution::candy(vector<int> &A) {
    vector<int> l2r(A.size(),1);
    vector<int> r2l(A.size(),1);
    vector<int> res(A.size());
    int sum = 0;
    for(int i = 1;i<A.size();i++)
    {
        if(A[i]>A[i-1]) l2r[i]=1+l2r[i-1];
    }
    for(int i = A.size()-2;i>=0;i--)
    {
        if(A[i]>A[i+1]) r2l[i]=1+r2l[i+1];
    }
    for(int i = 0;i<A.size();i++)
    {
        res[i]= max(l2r[i],r2l[i]);
    }
    for(int i = 0;i<A.size();i++)
    {
        sum+=res[i];
    }
    return sum;
}