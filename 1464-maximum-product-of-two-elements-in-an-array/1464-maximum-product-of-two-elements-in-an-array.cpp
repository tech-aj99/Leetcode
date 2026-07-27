class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long mul = (nums[i]-1) * (nums[j]-1);
                maxi = max(maxi , mul);
            }
        }
        return maxi;
    }
};