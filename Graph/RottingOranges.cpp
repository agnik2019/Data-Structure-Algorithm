class Solution {
public:
    struct elem {
        int row;
        int col;
        int depth;
    };
    vector<int> row_index = {0,0,-1,1};
    vector<int> col_index = {1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<elem> q;
        for(int i = 0; i<grid.size() ; i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j,0});
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            elem x = q.front();
            q.pop();
            int row = x.row;
            int col = x.col;
            int depth = x.depth;
            ans = max(ans,depth);
            for(int i =0; i<4; i++)
            {
                int new_row = row+row_index[i];
                int new_col = col+col_index[i];
                if(new_row >= 0 && new_row<r && new_col>=0 && new_col<c && grid[new_row][new_col] == 1)
                {
                    grid[new_row][new_col] = 2;
                    q.push({new_row,new_col,depth+1});
                }
            }
        }
         for(int i = 0; i< grid.size(); i++)
         {
            for(int j = 0; j< grid[0].size(); j++)
            {
                if(grid[i][j] == 1) 
                    return  -1;
             }
         }
        return ans;
    }
};