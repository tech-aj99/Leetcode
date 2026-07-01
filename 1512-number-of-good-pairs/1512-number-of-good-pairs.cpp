class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            ans += mp[nums[i]];   // add previous occurance to the number
            mp[nums[i]]++;        // increase freqeuncy of current number

        }
        return ans;
    }
};