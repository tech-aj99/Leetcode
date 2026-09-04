class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int maxi = INT_MIN;
            
            for(int k=0;k<=i;k++){
                maxi = max(maxi, nums[k]);
            }

            for(int k=i;k<n;k++){
                mini = min(mini, nums[k]);
            }
            
            if(maxi - mini <= k){
                return i;
            }
        }
        return -1;
    }
};