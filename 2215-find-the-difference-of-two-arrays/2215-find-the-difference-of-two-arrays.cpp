class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;

        for(int i=0; i<nums1.size(); i++){
            bool found = false, duplicate = false;

            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    found = true;
                    break;
                }
            }
            for(int k=0;k<ans1.size();k++){
                if(ans1[k] == nums1[i]){
                    duplicate = true;
                    break;
                }
            }
            if(!found && !duplicate){
                ans1.push_back(nums1[i]);
            }
        }

        for(int i=0; i<nums2.size(); i++){
            bool found = false, duplicate = false;

            for(int j=0; j<nums1.size(); j++){
                if(nums2[i] == nums1[j]){
                    found = true;
                    break;
                }
            }
            for(int k=0;k<ans2.size();k++){
                if(ans2[k] == nums2[i]){
                    duplicate = true;
                    break;
                }
            }
            if(!found && !duplicate){
                ans2.push_back(nums2[i]);
            }
        }
        return {ans1 , ans2};
    }
};