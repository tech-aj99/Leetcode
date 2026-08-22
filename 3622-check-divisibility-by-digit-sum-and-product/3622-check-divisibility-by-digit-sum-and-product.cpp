class Solution {
public:
    bool checkDivisibility(int n) {

        string num = to_string(n);
        int sum = 0;
        int product = 1;

        for(int i =0;i<num.size();i++){
            sum += (num[i] - '0');
            product *= (num[i] - '0');
        }

        if(n % (sum + product) == 0){
            return true;
        }
        return false;
    }
};