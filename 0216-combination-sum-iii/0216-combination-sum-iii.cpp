class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
   
    void solve(int k, int n, int start){
        if(k == 0){
            if(n == 0){
                ans.push_back(temp);
                return;
            }
        }

        if(n < 0) return;

        for(int num = start; num < 10; num++){
            temp.push_back(num);
            solve(k-1, n-num, num+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        solve(k , n, 1);
        return ans;
    }
};