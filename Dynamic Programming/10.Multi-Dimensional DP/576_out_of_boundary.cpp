class Solution {
public:
    const int M = 1e9+7;
    int solve(int m, int n, int N, int i, int j,vector<vector<vector<int>>> &dp)
    {
        if(i == m || j==n || i<0 || j<0)
            return 1;
        if(N==0) return 0;
        if(dp[N][i][j] >= 0) return dp[N][i][j]%M;
        
        int tmp = 0;
        tmp =(tmp+solve(m,n,N-1,i-1,j,dp))%M;
        tmp =(tmp+solve(m,n,N-1,i+1,j,dp))%M;
        tmp =(tmp+solve(m,n,N-1,i,j-1,dp))%M;
        tmp =(tmp+solve(m,n,N-1,i,j+1,dp))%M;
        
        
        dp[N][i][j] = tmp;
        return dp[N][i][j]%M;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(m,vector<int>(n,-1)));
        return solve(m,n,N,i,j,dp);
    }
};