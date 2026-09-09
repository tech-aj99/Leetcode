class Solution {
public:
    long long countCommas(long long n) {

        if(n >= 1 && n <= 999){
            return 0;
        }

        else if(n >= 1000 && n <= 999999){
            long long ans = n - 1000 + 1;
            return ans * 1;
        }

        else if(n >= 1000000 && n <= 999999999){
            long long ans1 = 999999 - 1000 + 1;
            long long ans2 = n - 1000000 + 1;

            return ans1 + (ans2 * 2);
        }

        else if(n >= 1000000000 && n <= 999999999999){
            long long ans1 = 999999 - 1000 + 1;
            long long ans2 = 999999999 - 1000000 + 1;
            long long ans3 = n - 1000000000 + 1;

            return ans1 + (ans2 * 2) + (ans3 * 3);
        }

        else if(n >= 1000000000000 && n <= 999999999999999){
            long long ans1 = 999999 - 1000 + 1;
            long long ans2 = 999999999 - 1000000 + 1;
            long long ans3 = 999999999999 - 1000000000 + 1;
            long long ans4 = n - 1000000000000 + 1;

            return ans1 + (ans2 * 2) + (ans3 * 3) + (ans4 * 4);
        }

        else {
            long long ans1 = 999999 - 1000 + 1;
            long long ans2 = 999999999 - 1000000 + 1;
            long long ans3 = 999999999999 - 1000000000 + 1;
            long long ans4 = 999999999999999 - 1000000000000 + 1;
            long long ans5 = n - 1000000000000000 + 1;

            return ans1 + (ans2 * 2) + (ans3 * 3)
                         + (ans4 * 4) + (ans5 * 5);
        }
    }
};