class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n/2;
        int count = 0;

        for(int i=0;i<n;i++){
            count += abs(nums[i] - nums[mid]);
        }
        return count;
    }
};