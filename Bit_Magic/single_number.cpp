int Solution::singleNumber(const vector<int> &A) {
    int xr = A[0];
    for(int i = 1; i< A.size(); i++)
    {
        xr ^= A[i];
    }
    return xr;
}
