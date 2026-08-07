class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; ;i++){
            string s = to_string(i);
            int product = 1;
            for(char ch : s){
                product *= (ch - '0');
            }
            if(product % t == 0){
                return i;
            }
        }
    }
};