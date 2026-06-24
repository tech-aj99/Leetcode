class Solution {
public:
    int compress(vector<char>& chars) {
        string ans;
        ans = "";
        if(chars.size() == 1){
            return 1;
        }
        int count = 1;
        for(int i=1;i<chars.size();i++){
            if(chars[i] == chars[i-1]){
                count++;
            }
            else{
                ans += chars[i-1];
                if(count > 1){
                    ans += to_string(count);
                }
                count = 1;
            }
        }
        // add the last character of group
        ans += chars.back();
        if(count > 1){
            ans += to_string(count);
        }

        // copy back into chars
        chars.clear();
        for(char ch : ans){
            chars.push_back(ch);
        }
        return chars.size();
    }
};