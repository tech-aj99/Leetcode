class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int mod = 1e9 + 7;

        vector<long long> dp(n+1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;

        for(int i=1;i<=n;i++){
            dp[i] = (2 * dp[i-1]) % mod;

            int ch = s[i - 1] - 'a';

            if(last[ch] != -1){
                dp[i] = (dp[i] - dp[last[ch]] + mod) % mod;
            }

            last[ch] = i - 1;
        } 
        return (dp[n] - 1 + mod) % mod;
    }
};