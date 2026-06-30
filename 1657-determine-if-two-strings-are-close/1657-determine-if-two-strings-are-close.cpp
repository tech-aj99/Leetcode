class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        unordered_set<char> s1;
        unordered_set<char> s2;

        // Count frequency and store unique characters
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
            s1.insert(word1[i]);
        }
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
            s2.insert(word2[i]);
        }

        // Check if both strings have the same unique characters
        if(s1 != s2){
            return false;
        }

        vector<int> arr1;
        vector<int> arr2;

        // Store frequencies
        for(auto it : mp1){
            arr1.push_back(it.second);
        }
        for(auto it : mp2){
            arr2.push_back(it.second);
        }

        // sort frequencies
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        return arr1 == arr2;
    }
};