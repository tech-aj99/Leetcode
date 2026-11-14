class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        int n = nums.size();

        for (int k = l; k <= r; k++) {
            int left = 0;
            int sum = 0;

            for (int right = 0; right < n; right++) {
                sum += nums[right];

                if (right - left + 1 == k) {
                    if (sum > 0) {
                        mini = min(mini, sum);
                    }
                    sum -= nums[left];
                    left++;
                }
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};