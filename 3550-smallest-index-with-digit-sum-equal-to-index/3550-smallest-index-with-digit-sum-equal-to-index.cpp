class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i < n;i++){
            if(nums[i] <= 9){
                if(nums[i] != i){
                    continue;
                }
                else{
                    return i;
                }
            }
            else if(nums[i] >= 10){
                string x = to_string(nums[i]);
                int sum = 0;

                for(int j =0;j<x.size();j++){
                    sum += x[j] - '0';
                }

                if(sum == i){
                    return i;
                }
            }
        }
        return -1;
    }
};