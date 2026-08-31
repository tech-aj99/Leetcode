class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<vector<int>> groups;
        groups.push_back({sorted[0]});

        for(int i=1;i<n;i++){
            if(sorted[i] - sorted[i-1] > limit){
                groups.push_back({});
            }
            groups.back().push_back(sorted[i]);
        }

        unordered_map<int, int> mp;
        for(int i=0;i<groups.size();i++){
            for(int x : groups[i]){
                mp[x] = i;
            }
        }

        vector<int> index(groups.size(), 0);

        for(int i=0;i<n;i++){
            int groupNumber = mp[nums[i]];

            nums[i] = groups[groupNumber][index[groupNumber]];

            index[groupNumber]++;
        }
        return nums;
    }
};