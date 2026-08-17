class Solution {
public:
    int solve(int l, int r, vector<int>& cumsum, vector<vector<int>> &dp){
        if(l >= r){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int score = 0;

        for(int mid = l;mid < r; mid++){
            int leftsum = cumsum[mid] - (l > 0 ? cumsum[l-1] : 0);
            int rightsum = cumsum[r] - cumsum[mid];

            if(leftsum < rightsum){
                score = max(score, leftsum + solve(l, mid, cumsum, dp));
            }
            else if(leftsum > rightsum){
                score = max(score, rightsum + solve(mid+1, r, cumsum, dp));
            }
            else{
                score = max({score, leftsum + solve(l, mid, cumsum, dp), rightsum + solve(mid+1, r, cumsum, dp)});
            }
        }
        return dp[l][r] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumsum(n);
        cumsum[0] = stoneValue[0];

        for(int i=1;i<n;i++){
            cumsum[i] = cumsum[i-1] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n-1, cumsum, dp);
    }
};