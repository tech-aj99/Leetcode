class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                continue;
            }
            else{
                ans += s[i];
            }
        }
        
        if(ans.empty()){
            return 0;
        }

        int sum = 0;
        for(int i=0;i<ans.size();i++){
            sum += ans[i] - '0';
        }
        return stoll(ans) * sum;
    }
};