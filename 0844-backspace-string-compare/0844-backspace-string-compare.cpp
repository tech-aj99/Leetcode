class Solution {
public:
    string solve(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i] == '#'){
                if(i == 0){
                    s.erase(i, 1);
                }
                else{
                    s.erase(i-1, 2);
                }
                i=-1;
            }
        }
        return s;
    }
    bool backspaceCompare(string s, string t){
        return solve(s) == solve(t);
    }
};