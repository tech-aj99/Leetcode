class Solution {
public:
    int maxDepth(string s) {
        int deapth = 0;
        int maxdeapth = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                deapth++;
                maxdeapth = max(maxdeapth, deapth);
            }
            else if(s[i] == ')'){
                deapth--;
            }
        }
        return maxdeapth;
    }
};