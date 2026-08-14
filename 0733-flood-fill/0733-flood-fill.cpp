class Solution {
public:
    void bfs(int sr, int sc, vector<vector<int>>& image, int color){
        int oldColor = image[sr][sc];

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == oldColor){
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        bfs(sr, sc, image, color);

        return image;
    }
};