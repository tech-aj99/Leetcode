class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] != 0) return 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j] - nums[i] == 2){
                    return nums[i]+1;
                }
                break;
            }
        }
        return nums.size();
    }
};