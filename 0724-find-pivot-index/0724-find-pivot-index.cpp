class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;

        // calculate total sum
        for(int i=0;i<n;i++){
            totalsum += nums[i];
        }

        // built prefix sum array
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int left = 0, right = 0;
        for(int index=0;index<n;index++){
            if(index == 0){
                left = 0;
                right = totalsum - left - nums[index];
            }
            else if(index == n-1){
                left = prefix[n-2];
                right = 0;
            }
            else{
                left = prefix[index-1];
                right = totalsum - left - nums[index];
            }
            if(left == right){
                return index;
            }
        }
        return -1;
    }
};