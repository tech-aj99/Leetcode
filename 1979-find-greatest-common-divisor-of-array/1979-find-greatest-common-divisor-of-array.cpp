class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            return gcd(nums[0] , nums[nums.size()-1]);
        }
        return -1;
    }
};