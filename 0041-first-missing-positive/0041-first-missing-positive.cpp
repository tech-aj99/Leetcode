class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;

        // Store all numbers in the map
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Check from 1 onwards
        for (int i = 1; i <= nums.size() + 1; i++) {
            if (mp.find(i) == mp.end()) {
                return i;
            }
        }

        return nums.size() + 1;
    }
};