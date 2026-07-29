class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = 0;
        int sumeven = 0;
        for(int i=1;i<=n;i++){
            sumeven += (i*2);
            sumodd += ((i*2)-1);
        }
        return gcd(sumeven, sumodd);
    }
};