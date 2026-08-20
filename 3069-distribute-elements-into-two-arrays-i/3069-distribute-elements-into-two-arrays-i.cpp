class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> p1;
        vector<int> p2;

        p1.push_back(nums[0]);
        p2.push_back(nums[1]);

        for(int i=2;i<nums.size();i++){
            if(p1.back() > p2.back()){
                p1.push_back(nums[i]);
            }
            else{
                p2.push_back(nums[i]);
            }
        }
        vector<int> ans;

        for(int x : p1){
            ans.push_back(x);
        }

        for(int x : p2){
            ans.push_back(x);
        }
        return ans;
    }
};