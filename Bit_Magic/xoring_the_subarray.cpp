int Solution::solve(vector<int> &A) {
    int n = A.size();
    int res = 0;
    for(int i = 0; i<n; i++)
    {
        int freq = (i+1)* (n-i);
        if(freq %2 == 1) 
              res = res^A[i];
    }
    return res;
}
