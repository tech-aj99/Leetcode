class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int count = 0;

        if(n % 2 == 1){
            return 0;
        }

        for(int i=0;i<n;i+=2){
            if(s[i] > s[i+1]){
                s[i+1]++;
                count++;
            }
            else if(s[i] < s[i+1]){
                s[i]++;
                count++;
            }
        }
        return count;
    }
};