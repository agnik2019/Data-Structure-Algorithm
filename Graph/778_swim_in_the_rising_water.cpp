class Solution {
public:
    vector<vector<int>> visited;
    int R,C;
    void dfs(vector<vector<int>> &grid, int mid, int x, int y)
    {
        if(!visited[x][y] && grid[x][y]<= mid)
        {
            visited[x][y] = true;
            if(x-1>= 0) dfs(grid,mid,x-1,y);
            if(x+1<R)  dfs(grid,mid,x+1,y);
            if(y-1>=0) dfs(grid,mid,x,y-1);
            if(y+1<C) dfs(grid,mid,x,y+1);
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int l = 0;
        int r = 50*50;
        R = grid.size();
        C = grid[0].size();
        while(l<r)
        {
            int mid = (l+r)/2;
            visited = vector<vector<int>>(R,vector<int>(C,0));
            dfs(grid,mid,0,0);
            if(visited[R-1][C-1])
                r = mid;
            else l = mid+1;
        }
        return l;
    }
};