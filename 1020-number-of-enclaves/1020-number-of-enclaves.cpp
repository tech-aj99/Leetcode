class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            // First column
            if(grid[i][0] == 1 && vis[i][0] == 0){
                vis[i][0] = 1;
                q.push({i, 0});
            }

            // Last Column
            if(grid[i][m-1] == 1 && vis[i][m-1] == 0){
                vis[i][m-1] = 1;
                q.push({i, m-1});
            }
        }

        for(int j=0;j<m;j++){
            // First Row
            if(grid[0][j] == 1 && vis[0][j] == 0){
                vis[0][j] = 1;
                q.push({0, j});
            }
            // Last Row
            if(grid[n-1][j] == 1 && vis[n-1][j] == 0){
                vis[n-1][j] = 1;
                q.push({n-1, j});
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0;k<4;k++){
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};