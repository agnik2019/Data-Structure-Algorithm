class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color,int newColor)
    {
        if(i<0 || j<0 || i>=image.size() || j>= image[0].size() || image[i][j] != color)
                return;
        image[i][j] = newColor;
        dfs(image,i-1,j,color,newColor);
        dfs(image,i,j-1,color,newColor);
        dfs(image,i+1,j,color,newColor);
        dfs(image,i,j+1,color,newColor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor)
            dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};