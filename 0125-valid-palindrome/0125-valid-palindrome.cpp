class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        
        for(char ch : s){
            if(isalnum(ch)){
                ch = tolower(ch);
                str += ch;
            }
        }

        int n = str.size();

        int left = 0;
        int right = n - 1;

        while(left <= right){
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};