class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        // prefix sum 0 seen before array starts
        mp[0] = -1;
        
        int sum = 0;
        int maxLen = 0;

        for(int i=0; i < nums.size();i++){
            // Treat 0 as -1 and 1 as +1
            if(nums[i] == 0){
                sum--;
            }
            else{
                sum++;
            }
            // Same sum found before
            if(mp.find(sum) != mp.end()){
                // Subarray between previous index and current index
                // has equal number of 0s and 1s
                maxLen = max(maxLen, i-mp[sum]);
            }
            else{
                // Store first occurrence of sum
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};