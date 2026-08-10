class Solution {
public: 
    bool isPalindrome(string temp2){
        int i = 0;
        int j = temp2.size()-1;
        while(i < j){
            if(temp2[i] != temp2[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> ans;
    vector<string> temp;

    void solve(string s, int index){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < s.size(); i++){
            string temp2 = s.substr(index, i - index + 1);
            if(isPalindrome(temp2)){
                temp.push_back(temp2);
                solve(s, i+1);
                temp.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};