class Solution {
public:
    int isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int count = 0;
        //First Window
        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        int maxCount = count;

        // Slide the Window
        for(int i=k; i<s.size();i++){
            if(isVowel(s[i-k])){
                count--;
            }
            if(isVowel(s[i])){
                count++;
            }
            maxCount = max(maxCount , count);
        }
        return maxCount;
    }
};