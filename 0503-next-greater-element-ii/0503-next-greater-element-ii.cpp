class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int nextGreater = -1;
            for(int j=1;j<n;j++){
                int idx = (i+j)%n;  // Circular Traversal

                if(nums[idx] > nums[i]){
                    nextGreater = nums[idx];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};