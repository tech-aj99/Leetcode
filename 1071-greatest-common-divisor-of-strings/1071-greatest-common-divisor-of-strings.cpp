class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // fing smaller string length
        int n = min(str1.length(), str2.length());

        // Try every possible prefix length(largest to smallest)
        for(int len = n;len >= 1; len--){

            if(str1.length() % len != 0 && str2.length() % len != 0){
                continue;
            }
            string candidate = str1.substr(0, len);

            string temp1 = "";
            string temp2 = "";

            while(temp1.length() < str1.length()){
                temp1 += candidate;
            }
            while(temp2.length() < str2.length()){
                temp2 += candidate;
            }
            if(temp1 == str1 && temp2 == str2){
                return candidate;
            }
        }
        return "";
    }
};