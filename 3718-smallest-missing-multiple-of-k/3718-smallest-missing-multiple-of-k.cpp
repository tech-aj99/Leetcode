class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(int i = 1; i <= n+1; i++){
            int multiple = i * k;

            if(mp.find(multiple) == mp.end()){
                return multiple;
            }
        }
        return -1;   
    }
};