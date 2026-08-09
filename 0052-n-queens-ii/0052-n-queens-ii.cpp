class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        // upper left diagonal
        int r = row, c = col;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // left side
        r = row;
        c = col;
        while(c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;
        }

        // lower-left digoanl
        r = row;
        c = col;
        while(r < n && c >= 0){
            if(board[r][c] == 'Q') return false;
            r++;
            c--;
        }
        return true;
    }

    void solve(int col, vector<string> &board, int n, int &count){
        if(col == n){
            count++;
            return;
        }

        for(int row=0;row < n;row++){
            if (isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, n, count);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        int count = 0;
        solve(0, board, n, count);
        return count;
    }
};