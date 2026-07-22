class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        n = 1;

        for(int i=0;i < target.size();i++){
            while(n < target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                n++;
            }
            ans.push_back("Push");
            n++;
        }
        return ans;
    }
};