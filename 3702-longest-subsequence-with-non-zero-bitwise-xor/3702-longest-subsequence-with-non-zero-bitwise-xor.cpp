class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;

        for(int num : nums){
            xorr = xorr ^ num;
        }

        if(xorr != 0){
            return nums.size();
        }

        for(int num : nums){
            if(num != 0){
                return nums.size()-1;
            }
        }
        return 0;
    }
};