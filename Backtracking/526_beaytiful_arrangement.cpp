class Solution {
public:
    void permute(int pos,int n, vector<bool>& visited, int &count)
    {
        if(pos>n) count++;
        for(int i = 1; i<= n; i++)
        {
            if(!visited[i] && (pos%i == 0 || i%pos ==0))
            {
                visited[i] = true;
                permute(pos+1,n,visited, count);
                visited[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> visited(n+1,false);
        int count = 0;
        permute(1,n,visited,count);
        return count;
    }
};