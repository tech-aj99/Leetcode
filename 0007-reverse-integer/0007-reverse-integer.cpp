class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        int n = str.size();
        int left = 0;
        int right = n-1;

        if(str[0] == '-'){
            left = 1;
        }

        while(left < right){
            swap(str[left], str[right]);
            left++;
            right--;
        }
        
        long long num = stoll(str);

        if(num > INT_MAX || num < INT_MIN){
            return 0;
        }
        return num;
    }
};