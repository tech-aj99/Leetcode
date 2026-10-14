class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        if(sum > 9 * num) return "";

        while(num > 0){
            int take = min(9, sum);

            ans += to_string(take);

            sum = sum - take;
            num--;
        }
        return ans;
    }
};