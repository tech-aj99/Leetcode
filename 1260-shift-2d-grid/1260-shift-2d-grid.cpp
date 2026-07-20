class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> arr;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr.push_back(grid[i][j]);
            }
        }

        while(k > 0){
            int last = arr[arr.size() - 1];

            for(int i=arr.size()-1;i>0;i--){
                arr[i] = arr[i-1];
            }
            arr[0] = last;
            k--;
        }

        vector<vector<int>> mat(rows, vector<int> (cols));

        for(int i=0;i<arr.size();i++){
            int row = i / cols;
            int col = i % cols;

            mat[row][col] = arr[i];
        }
        return mat;
    }
};