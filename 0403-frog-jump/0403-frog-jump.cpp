class Solution {
public:
    int n;
    vector<vector<int>> dp;
    unordered_map<int, int> mp;

    bool solve(vector<int>& stones, int idx, int jump){
        if(idx == n-1){
            return true;
        }

        if(dp[idx][jump] != -1){
            return dp[idx][jump];
        }

        bool ans = false;

        for(int nextJump = jump-1; nextJump <= jump+1; nextJump++){
            if(nextJump <= 0){
                continue;
            }

            int nextpos = stones[idx] + nextJump;

            if(mp.find(nextpos) != mp.end()){
                int nextIdx = mp[nextpos];

                if(solve(stones, nextIdx, nextJump)){
                    ans = true;
                    break;
                }
            }
        }
        return dp[idx][jump] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        n = stones.size();

        if(stones[1] != 1){
            return false;
        }

        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }

        dp.assign(n, vector<int> (n+1, -1));

        return solve(stones, 1, 1);
    }
};