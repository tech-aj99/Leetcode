class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int row, int col, int i){
        if(i == word.size()) return true;

        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size()){
            return false;
           }
        
        if(board[row][col] != word[i])  return false;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = solve(board, word, row+1, col, i+1) || 
                     solve(board, word, row-1, col, i+1) ||
                     solve(board, word, row, col+1, i+1) || 
                     solve(board, word, row, col-1, i+1);

        board[row][col] = temp;

        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0;row < board.size();row++){
            for(int col = 0;col < board[0].size();col++){

                if(board[row][col] == word[0]){
                    if(solve(board, word, row, col, 0))
                        return true;
                }
            }
        }
        return false;
    }
};