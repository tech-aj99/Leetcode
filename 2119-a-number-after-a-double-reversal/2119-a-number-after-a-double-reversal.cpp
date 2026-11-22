class Solution {
public:
    bool isSameAfterReversals(int num) {
        int ans = 0;
        int ans1 = num;

        string str1 = to_string(num);
        reverse(str1.begin(), str1.end());
        ans = stoi(str1);

        string str2 = to_string(ans);
        reverse(str2.begin(), str2.end());

        ans = stoi(str2);

        if(ans == ans1){
            return true;
        }
        return false;
    }
};