class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int oddnum = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums1[i] % 2 != 0){
                oddnum = min(oddnum, nums1[i]);
            }
        }

        if(oddnum == INT_MAX){
            return true;
        }

        for(int i=0;i<n;i++){
            if(nums1[i] % 2 == 0 && nums1[i] < oddnum){
                return false;
            }
        }
        return true;
    }
};