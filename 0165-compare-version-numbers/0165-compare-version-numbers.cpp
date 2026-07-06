class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        string temp1 = "";

        for(char ch : version1){
            if(ch =='.'){
                v1.push_back(stoi(temp1));
                temp1 = "";
            }
            else{
                temp1 += ch;
            }
        }
        v1.push_back(stoi(temp1));   // last number

        vector<int> v2;
        string temp2 = "";

        for(char ch : version2){
            if(ch =='.'){
                v2.push_back(stoi(temp2));
                temp2 = "";
            }
            else{
                temp2 += ch;
            }
        }
        v2.push_back(stoi(temp2));   // last number

        int n = max(v1.size(), v2.size());

        for(int i=0;i<n;i++){
            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;

            if(num1 < num2){
                return -1;
            }
            else if(num1 > num2){
                return 1;
            }
        }
        return 0;
    }
};