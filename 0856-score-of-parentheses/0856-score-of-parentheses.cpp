class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int deapth = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                deapth++;
            }
            else{
                deapth--;
                if(s[i-1] == '('){
                    ans += pow(2, deapth);
                }
            }
        }
        return ans;
    }
};