class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp; // value -> index

        for(int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i]; // required number
            // If complement exists
            if(mp.find(remain) != mp.end()) {
                return {mp[remain], i}; // return indices
            }
            mp[nums[i]] = i; // store number and index
        }

        return {}; // no pair found
    }
};