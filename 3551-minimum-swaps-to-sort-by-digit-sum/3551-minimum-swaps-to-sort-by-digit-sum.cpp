class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> arr;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            string str = to_string(nums[i]);
            int sum = 0;
            
            for(int j = 0;j < str.size();j++){
                sum += str[j] - '0';
            }
            arr.push_back({sum, nums[i]});
        }

        sort(arr.begin(), arr.end());

        vector<int> target;
        for(auto x : arr){
            target.push_back(x.second);
        }

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == target[i]){
                continue;
            }

            int j = mp[target[i]];

            mp[nums[i]] = j;
            mp[nums[j]] = i;

            swap(nums[i], nums[j]);
            count++;
        }
        return count;
    }
};