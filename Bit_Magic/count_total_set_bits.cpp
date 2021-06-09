int Solution::solve(int A) {
    if(A==0)return 0;
    long long int mx = log2(A);
    long long int x = pow(2,mx);
    x%=1000000007;
    return (x/2*mx+(A-x+1)+solve(A-x))%1000000007;
}
