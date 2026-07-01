class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;       // store rows with their frequencies

        for(int i=0;i<grid.size();i++){
            mp[grid[i]]++;
        }
        int ans = 0;

        for(int j=0;j<n;j++){
            vector<int> col;
            for(int i=0;i<n;i++){
                col.push_back(grid[i][j]);
            }

            if(mp.find(col) != mp.end()){
                ans += mp[col];
            }
        }
        return ans;
    }
};