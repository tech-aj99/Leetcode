class Solution {
public:
    vector<int> t;
    bool solve(int n){
        // No stones
        if(n == 0) return false;

        // Already calculated
        if(t[n] != -1){
            return t[n] == 1 ? true : false;
        }

        // Try every square
        for(int k = 1; k * k <= n; k++){
            // Opponent loses
            if(solve(n - (k * k)) == false){
                return t[n] = true;
            }
        }
        // No winning move
        return t[n] = false;
    }
    bool winnerSquareGame(int n) {
        t.assign(n+1, -1);
        return solve(n);
    }
};