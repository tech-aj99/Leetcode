class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p1;
        vector<int> p2;
        vector<int> ans;

        for(int i =0;i< nums.size();i++){
            if(nums[i] < 0){
                p2.push_back(nums[i]);
            }
            else{
                p1.push_back(nums[i]);
            }
        }

        for(int i=0;i<p1.size();i++){
            ans.push_back(p1[i]);
            ans.push_back(p2[i]);
        }
        return ans;
    }
};