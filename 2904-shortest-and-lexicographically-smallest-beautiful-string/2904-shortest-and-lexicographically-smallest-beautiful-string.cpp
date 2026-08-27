class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int count = 0;

        string ans = "";
        int minLen = INT_MAX;

        for(int right = 0;right < s.size();right++){
            if(s[right] == '1'){
                count++;
            }

            if(count == k){
                while(s[left] == '0'){
                    left++;
                }

                int len = right - left + 1;
                string curr = s.substr(left, len);

                if(len < minLen){
                    minLen = len;
                    ans = curr;
                }

                else if(len == minLen && curr < ans){
                    ans = curr;
                }

                count--;
                left++;
            }
        }
        return ans;
    }
};