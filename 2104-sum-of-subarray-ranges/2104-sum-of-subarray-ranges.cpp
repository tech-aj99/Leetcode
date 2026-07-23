class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int i=0;i<nums.size();i++){
            int mn = nums[i];
            int mx = nums[i];

            for(int j=i;j<n;j++){
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);

                ans += (mx - mn);
            }
        }
        return ans;
    }
};