class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        vector<int> arr;

        for(char ch : s){
            arr.push_back(ch - '0');
        }

        int maxi = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                maxi = max(maxi , arr[i] * arr[j]);
            }
        }
        return maxi;
    }
};