class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int ans = num;
        for(int i=0;i<s.size();i++){
            for(int j = i+1; j< s.size();j++){
                if(s[i] < s[j]){
                    swap(s[i], s[j]);

                    ans = max(ans, stoi(s));

                    swap(s[i] , s[j]);   // undo the swap
                }
            }
        }
        return ans;
    }
};