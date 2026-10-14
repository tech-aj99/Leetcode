class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";
        
        int nines = sum / 9;
        int remain = sum % 9;

        string ans = "";

        while(nines > 0){
            ans += '9';
            nines--;
        }

        if(remain > 0){
            ans += to_string(remain);
        }

        while(ans.size() < num){
            ans += '0';
        }

        return ans;
    }
};