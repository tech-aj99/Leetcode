class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            // First column
            if(board[i][0] == 'O' && vis[i][0] == 0){
                vis[i][0] = 1;
                q.push({i, 0});
            }

            // Last Column
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0){
                vis[i][m-1] = 1;
                q.push({i, m-1});
            }
        }

        for(int j=0;j<m;j++){
            // First Row
            if(board[0][j] == 'O' && vis[0][j] == 0){
                vis[0][j] = 1;
                q.push({0, j});
            }
            // Last Row
            if(board[n-1][j] == 'O' && vis[n-1][j] == 0){
                vis[n-1][j] = 1;
                q.push({n-1, j});
            }
        }

        //BFS
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};