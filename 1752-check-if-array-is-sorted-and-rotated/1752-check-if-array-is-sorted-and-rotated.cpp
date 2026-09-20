class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for(int x=0;x<nums.size();x++){
            vector<int> temp = nums;

            reverse(temp.begin(), temp.begin()+x);
            reverse(temp.begin()+x, temp.end());
            reverse(temp.begin(), temp.end());

            if(temp == sorted){
                return true;
            }
        }
        return false;
    }
};