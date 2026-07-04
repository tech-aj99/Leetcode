class Solution {
public:
    string makeGood(string s) {
        for(int i=1;i<s.size();i++){
            if(abs(s[i-1] - s[i]) == 32){
                s.erase(i-1, 2);
                i = 0;
            }
        }
        return s;
    }
};