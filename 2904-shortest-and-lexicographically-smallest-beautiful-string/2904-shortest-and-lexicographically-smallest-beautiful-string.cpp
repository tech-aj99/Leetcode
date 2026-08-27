class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int minLen = INT_MAX;

        for(int i=0;i<s.size();i++){
            int count = 0;

            for(int j=i;j<s.size();j++){
                if(s[j] == '1'){
                    count++;
                }

                if(count > k){
                    break;
                }

                if(count == k){
                    string curr = s.substr(i, j-i+1);

                    if(curr.size() < minLen){
                        minLen = curr.size();
                        ans = curr;
                    }

                    else if(curr.size() == minLen && curr < ans){
                        ans = curr;
                    }
                }
            }
        }
        return ans;
    }
};