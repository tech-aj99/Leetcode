class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        
        for(int i : nums){
            mp[i]++;
        }

        int index = 0;
        for(auto it : mp){
            for(int j=0;j<it.second;j++){
                nums[index] = it.first;
                index++;
            }
        }
    }
};