class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // Count remainders
        for (int x : stones) {
            if (x % 3 == 0)
                cnt0++;
            else if (x % 3 == 1)
                cnt1++;
            else
                cnt2++;
        }

        if(cnt1 == 0 || cnt2 == 0){
            return max(cnt1, cnt2) > 2 && cnt0 % 2 == 1;
        }
        return abs(cnt1 - cnt2) > 2 || cnt0 % 2 == 0;
    }
};