class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        unordered_set<int> s;
        int count = 1;

        for(int i=1;i<arr.size();i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                // check if frequesncy already exists
                if(s.find(count) != s.end()){  
                    return false;
                }
                s.insert(count);
                count = 1;
            }
        }
        // check frequency of last element
        if(s.find(count) != s.end()){
            return false;
        }
        return true;
    }
};