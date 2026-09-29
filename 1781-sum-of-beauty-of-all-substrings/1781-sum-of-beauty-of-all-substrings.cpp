class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for(int i=0;i<s.size();i++){
            unordered_map<char, int> mp;

            for(int j=i;j<s.size();j++){

                mp[s[j]]++;

                int maxi = 0;
                int mini = INT_MAX;

                for(auto it : mp){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                ans += (maxi - mini);

            }
        }
        return ans;
    }
};