class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;

        for(int i = 0; i < nums1.size(); i++){
            if(find(nums2.begin(), nums2.end(), nums1[i]) == nums2.end() && 
               find(ans1.begin(), ans1.end(), nums1[i]) == ans1.end()){
                ans1.push_back(nums1[i]);
           }
        }

        for(int i = 0; i < nums2.size(); i++){
            if(find(nums1.begin(), nums1.end(), nums2[i]) == nums1.end() && 
               find(ans2.begin(), ans2.end(), nums2[i]) == ans2.end()){
                ans2.push_back(nums2[i]);
           }
        }
        return {ans1 , ans2};
    }
};