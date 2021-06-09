int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int mn = INT_MAX;
    for(int i = 0; i< A.size()-1; i++){
        int xx = A[i]^A[i+1];
        mn = min(xx,mn);
    }
    return mn;
}
