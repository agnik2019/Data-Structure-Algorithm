int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size() == 0) return 0;
    vector<int> lis(A.size(),1); // lis of left to right
    vector<int> lds(A.size(),1); // lis of right to left
    for(int i = 1; i< A.size(); i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(A[j] < A[i])
                lis[i] = max(lis[i], lis[j]+1);
        }
    }
    for(int i = A.size()-2; i>= 0; i--)
    {
        for(int j = A.size()-1; j>i; j--)
        {
            if(A[j] < A[i])
                lds[i] = max(lds[i], lds[j]+1);
        }
    }
    int mx = lis[0]+lds[0]-1;
    for(int i = 1; i<A.size(); i++)
        mx = max(mx, lis[i]+lds[i]-1);
        
    return mx;

}