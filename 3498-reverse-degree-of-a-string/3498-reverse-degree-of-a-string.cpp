class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i=0;i<s.size();i++){
            int value = 1 * (s[i] - 'a') + 1;
            int current = 27 - value;

            ans += current * (i+1);
        }

        return ans;
    }
};