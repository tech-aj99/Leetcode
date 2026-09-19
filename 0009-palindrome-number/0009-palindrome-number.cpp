class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int n = str.size();

        int left = 0;
        int right = n - 1;

        if(str[0] == '-'){
            return false;
        }

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