class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int left=0;left <= n-k; left++){
            unordered_map<int, int> temp;

            for(int right=left;right < left+k;right++){
                temp[nums[right]]++;
            }

            for(auto it : temp){
                mp[it.first]++;
            }
        }
        
        int ans = -1;

        for(auto it : mp){
            if(it.second == 1){
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};