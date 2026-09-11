class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int count = 0;
        set<int> s;
        
        for(int i=0;i<n;i++){
            
            if(digits[i] == 0){
                continue;
            }

            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i != j && j != k && k != i){
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                        if(num % 2 == 0){
                            s.insert(num);
                        }
                    }
                }
            }
        }
        return s.size();
    }
};