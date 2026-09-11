class Solution {
public:
    void solve(vector<int>& digits, vector<bool> &used, int num, int count, set<int> &s){
        if(count == 3){
            if(num % 2 == 0){
                s.insert(num);
            }
            return;
        }

        for(int i=0;i<digits.size();i++){
            if(used[i]) continue;

            if(count == 0 && digits[i] == 0){
                continue;
            }

            used[i] = true;

            solve(digits, used, num * 10 + digits[i], count+1, s);

            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<bool>used(n, false);
        set<int> s;

        solve(digits, used, 0, 0, s);

        return s.size();
    }
};