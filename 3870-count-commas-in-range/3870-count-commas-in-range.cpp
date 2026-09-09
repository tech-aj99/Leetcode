class Solution {
public:
    int countCommas(int n) {
        string num = to_string(n);

        if(num.size() < 4){
            return 0;
        }
        else{
            return n - 1000 + 1;
        }
    }
};