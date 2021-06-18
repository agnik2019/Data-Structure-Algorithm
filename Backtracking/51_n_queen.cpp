class Solution {
public:
    vector<vector<string>> sol;
    
    bool place(vector<string> &board,int row, int col)
    {
        int i,j;
        int n = board.size();
        for(int i = 0; i< col; i++)
            if(board[row][i]=='Q') return false;
        //check left sided diagonal
        for(int i = row, j = col; i<n && j>=0; i++,j--)
            if(board[i][j]=='Q') return false;
        //check right sided diagonal
        for(int i = row, j = col; i>=0 && j>=0; i--,j--)
            if(board[i][j]=='Q') return false;
        
        return true;
    }
    void solve(vector<string> &board,int col,int n)
    {
        if(col == n)
        {
            sol.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++)
        {
            if(place(board,row,col))
            {
                board[row][col] ='Q';
                solve(board,col+1,n);
                board[row][col]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0,n);
        return sol;
    }
};