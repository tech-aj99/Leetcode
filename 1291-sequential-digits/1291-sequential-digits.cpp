class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;

        // start with single digits
        for(int i=1;i<=8;i++){
            q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
        
        // valid sequential number
        if(temp >= low && temp <= high){
            ans.push_back(temp);
        }
        int last_digit = temp % 10; // Get last digit

        // Append last digit
        if(last_digit + 1 <= 9){
            q.push(temp*10 + (last_digit + 1));
        }
      }
      return ans;
    }
};