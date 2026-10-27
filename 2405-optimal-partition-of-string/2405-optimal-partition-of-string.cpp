class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int count = 0;
        int start = 0;

        for(int i=0;i<n;i++){
            bool duplicate = false;

            for(int j=start;j<i;j++){
                if(s[j] == s[i]){
                    duplicate = true;
                    break;
                }
            }

            if(duplicate){
                count++;
                start = i;
            }
        }
        return count+1;
    }
};