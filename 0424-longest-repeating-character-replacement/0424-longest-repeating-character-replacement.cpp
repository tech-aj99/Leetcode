class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxCount = 0;
        int maxFreq = 0;   // highest frequency in current window

        unordered_map<char, int> mp;

        for(int right=0;right<s.size();right++){
            mp[s[right]]++;   // Add current number

            maxFreq = max(maxFreq, mp[s[right]]);   // update max frequency
            // replacements needed = window size - maxFreq
            while((right-left+1) - maxFreq > k){
                mp[s[left]]--;   // Remove left character
                left++;          // Shirnk Window
            }
            maxCount = max(maxCount, right-left+1);  // Update ans
        }
        return maxCount;
    }
};