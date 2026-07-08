class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;

        // store all elements in map
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int expected = 1;
        // Traverse the map
        for(auto it : mp){
            if(it.first <= 0){
                continue;
            }
            if(it.first == expected){
                expected++;
            }
            else if(it.first > expected){
                return expected;
            }
        }
        return expected;
    }
};