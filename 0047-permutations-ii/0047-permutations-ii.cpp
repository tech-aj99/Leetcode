class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;

    void solve(vector<int>& nums, int index){
        if(index == nums.size()){
            if(st.find(nums) == st.end()){
                st.insert(nums);
                ans.push_back(nums);
            }
            return;
        }

        for(int i =index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            solve(nums, index+1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};