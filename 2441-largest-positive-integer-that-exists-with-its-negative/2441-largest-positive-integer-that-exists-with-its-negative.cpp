class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int ans = -1;

        for(int i=0;i<n;i++){
            if(nums[i] > 0 && mp.find(-nums[i]) != mp.end()){
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};