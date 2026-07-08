class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int roll = rolls.size() + n;
        int totalSum = roll * mean;

        int currentSum = 0;
        for(int i=0;i<rolls.size();i++){
            currentSum += rolls[i];
        }

        int missingSum = totalSum - currentSum; 
        // Impossible if missing sum cannot be formed using n dice (1 to 6)
        if(missingSum < n || missingSum > 6 * n)
            return {};

        // Fill all missing rolls with the base value
        vector<int> ans(n, missingSum/n);
        
        // Distribute the remaining sum (+1) to the first 'rem' elements
        int rem = missingSum % n;
        for(int i=0;i<rem;i++){
            ans[i]++;
        }
        return ans;
    }
};