class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }

        vector<int> temp;
        for(int i=1;i<=n+1;i++){
            temp.push_back(i * k);
        }

        for(int i =0;i<temp.size();i++){
            if(mp.find(temp[i]) == mp.end()){
                return temp[i];
            }
        }
        return -1;
    }
};