class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int maxi = 0;
        vector<int> freq(26, 0);

        for(int right = 0;right < s.size(); right++){
            freq[s[right] - 'a']++;

            while(freq[s[right] - 'a'] > 2){
                freq[s[left] - 'a']--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};