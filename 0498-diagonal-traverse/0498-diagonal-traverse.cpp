class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int rows = mat.size();
        int cols = mat[0].size();
        for(int d=0;d<rows+cols-1;d++){
            vector<int> temp;

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(i+j == d){
                        temp.push_back(mat[i][j]);
                    }
                }
            }
            if(d % 2 == 0){
                reverse(temp.begin(), temp.end());
            }
            for(int x : temp){
                ans.push_back(x);
            }
        }
        return ans;
    }
};