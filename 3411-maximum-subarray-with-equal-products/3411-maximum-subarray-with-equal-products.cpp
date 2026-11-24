class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i =0;i<n;i++){
            long long prod = 1;
            long long lcm = 1;
            long long g = 0;

            for(int j=i;j<n;j++){
                prod *= nums[j];
                g = gcd(g, nums[j]);
                lcm = lcm / gcd(lcm, (long long) nums[j]) * nums[j];

                if(prod == g * lcm){
                    maxi = max(maxi, j - i + 1);
                }

                if(prod > 1e9) break;
            }
        }
        return maxi;
    }
};