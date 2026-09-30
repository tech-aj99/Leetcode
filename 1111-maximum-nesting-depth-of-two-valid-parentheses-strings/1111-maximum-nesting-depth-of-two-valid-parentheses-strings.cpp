class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);
        int deapth = 0;

        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                deapth++;
                ans[i] = (deapth % 2 == 0) ? 0 : 1;
            }
            else{
                ans[i] = (deapth % 2 == 0) ? 0 : 1;
                deapth--;
            }
        }
        return ans;
    }
};