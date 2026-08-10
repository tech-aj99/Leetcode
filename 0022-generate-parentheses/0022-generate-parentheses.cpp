class Solution {
public: 
    vector<string> ans;
    string temp;

    void solve(int n , int open, int close){
        if(temp.size() == 2 * n){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            temp += '(';
            solve(n, open+1, close);
            temp.pop_back();
        }

        if(close < open){
            temp += ')';
            solve(n, open, close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0);
        return ans;
    }
};