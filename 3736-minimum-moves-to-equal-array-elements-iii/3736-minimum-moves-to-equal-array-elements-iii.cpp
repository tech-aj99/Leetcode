class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int last = nums[n-1];
        int count = 0;

        for(int i=0;i<n;i++){
            count += (last - nums[i]);
        }
        return count;
    }
};