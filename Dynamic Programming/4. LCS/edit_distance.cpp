int Solution::minDistance(string A, string B) {
    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
    dp[0][0] = 0;
    for(int i = 1; i<= A.size(); i++) dp[i][0] = i;
    for(int i = 1; i<= B.size(); i++) dp[0][i] = i;
    
    for(int i = 1; i<=A.size(); i++)
    {
        for(int j = 1; j<= B.size(); j++)
        {
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+ min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
        }
    }
    return dp[A.size()][B.size()];
}
