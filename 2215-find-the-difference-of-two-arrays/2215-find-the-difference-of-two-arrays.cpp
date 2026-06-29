class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Store unique elements from both arrays
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> ans1;
        vector<int> ans2;

        // Find elements present in nums1 but not in nums2
        for(int x : s1){
            if(s2.find(x) == s2.end()){    // x not found in s2
                ans1.push_back(x);
            }
        }

        // Find elements present in nums2 but not in nums1
        for(int x : s2){
            if(s1.find(x) == s1.end()){    // x not found in s1
                ans2.push_back(x);
            }
        }
        return {ans1, ans2};
    }
};