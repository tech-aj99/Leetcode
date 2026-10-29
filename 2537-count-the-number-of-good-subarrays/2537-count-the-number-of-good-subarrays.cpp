class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        long long pairs = 0;
        unordered_map<int, int> mp;

        for(int right=0;right<n;right++){
            pairs += mp[nums[right]];
            mp[nums[right]]++;

            while(pairs >= k){
                ans += n - right;

                mp[nums[left]]--;
                pairs -= mp[nums[left]];

                left++;
            }
        }
        return ans;
    }
};