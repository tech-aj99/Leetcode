class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    string sortVowels(string s) {
        vector<char> temp;
        for(char ch : s){
            if(isVowel(ch)){
                temp.push_back(ch);
            }
        }
        sort(temp.begin() , temp.end());
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};