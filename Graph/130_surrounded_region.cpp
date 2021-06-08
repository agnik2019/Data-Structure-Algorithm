 #include<iostream>
#include<vector>

using namespace std;
    void change(vector<vector<char>>& A,int x, int y)
    {
        A[x][y]='#';
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        for(int i = 0; i<4; i++)
        {
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(cx>=0 && cx<A.size() && cy>=0 && cy<A[0].size() && A[cx][cy] == 'O')
                change(A,cx,cy);
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0; i< board.size(); i++)
        {
            for(int j = 0; j<board[0].size(); j++)
            {
               if(i==0 || i== board.size()-1 || j==0 || j== board[0].size()-1) 
                if(board[i][j]=='O' )
                    change(board,i,j);
            }
        }
         for(int i=0; i< board.size(); i++)
        {
            for(int j = 0; j<board[0].size(); j++)
            {
                if(board[i][j]== 'O')
                    board[i][j]='X';
            }
        }

        for(int i=0; i< board.size(); i++)
        {
            for(int j = 0; j<board[0].size(); j++)
            {
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
        
        
    }
    int main(){
        int n,m; cin>>n>>m;
        vector<vector<char>> graph(n,vector<char>(m));
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                cin>>graph[i][j];
        solve(graph);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }