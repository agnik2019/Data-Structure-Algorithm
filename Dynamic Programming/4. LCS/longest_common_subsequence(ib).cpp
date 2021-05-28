int Solution::solve(string A, string B) {
    int m = A.length();
    int n = A.length();
    //vector<vector<int>> lcs(0,vector<int>(0));
    int lcs[m+1][n+1];
    for(int i = 0; i<=m;i++)
    {
        for(int j = 0; j<=n;j++)
        {
            if(i == 0 || j==0)
                lcs[i][j]=0;
        }
    }
    for(int i = 1; i<=m;i++)
    {
        for(int j = 1; j<=n;j++)
        {
            if(A[i-1] == B[j-1])
                lcs[i][j] = 1+lcs[i-1][j-1];
            else
                lcs[i][j]= max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[m][n];
}