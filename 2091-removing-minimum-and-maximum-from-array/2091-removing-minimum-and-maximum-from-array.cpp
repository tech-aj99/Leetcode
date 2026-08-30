class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        int j = -1;
        int k = -1;

        for(int i=0;i<nums.size();i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == maxi){
                j = i;
                break;
            }
        }

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == mini){
                k = i;
                break;
            }
        }

        int left = min(j, k);
        int right = max(j, k);

        int option1 = right + 1;
        int option2 = n - left;
        int option3 = left + 1 + n - right;

        return min({option1, option2, option3});
    }
};