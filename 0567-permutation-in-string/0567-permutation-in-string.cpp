class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if(m > n) return false;
        
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // frequency of s1
        for(char ch : s1){
            freq1[ch - 'a']++;
        }
        int left = 0;

        for(int right=0; right < n; right++){
            freq2[s2[right] - 'a']++; // add current character

            // shrink if window size > m
            if(right - left + 1 > m){
                freq2[s2[left] - 'a']--;
                left++;
            }
            if(freq1 == freq2){
                return true;
            }
        }
        return false;
    }
};