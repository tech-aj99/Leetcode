class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word, vector<vector<int>> &visited, int row, int col, int i){
        if(i == word.size()) return true;

        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size()){
            return false;
           }
        
        if(visited[row][col] || board[row][col] != word[i])  return false;

        visited[row][col] = 1;

        if(solve(board, word, visited, row+1, col, i+1) || 
                     solve(board, word, visited, row-1, col, i+1) ||
                     solve(board, word, visited, row, col+1, i+1) || 
                     solve(board, word, visited, row, col-1, i+1)){
                        return true;
                     }

        visited[row][col] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int row = 0;row < n;row++){
            for(int col = 0;col < m;col++){

                if(board[row][col] == word[0]){
                    if(solve(board, word, visited, row, col, 0))
                        return true;
                }
            }
        }
        return false;
    }
};