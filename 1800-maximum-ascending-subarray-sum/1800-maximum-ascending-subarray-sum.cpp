class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxi = nums[0];

        for(int i=0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                ans += nums[i+1];
            }  
            else{
                ans = nums[i+1];
            }
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};