class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;

        for(int& x : nums){
            x = abs(x);
            x = x * x;
        }

        sort(nums.begin(), nums.end());

        for(int i=0;i<n/2;i++){
            score -= nums[i];
        }

        for(int i=n/2;i<n;i++){
            score += nums[i];
        }
        return score;
    }
};