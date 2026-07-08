class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i] == 'b' && s[i+1] == 'a'){
                return false;
            }
            if(s[n-2] == 'b' && s[n-1] == 'a'){
                return false;
            }
            if(s[0] == 'b' && s[1] == 'a'){
                return false;
            }

        }
        return true;
    }
};