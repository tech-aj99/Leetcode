class Solution {
public:
    int getValue(int i){
        if(i < 8){
            return 1;
        }
        else if(i < 16){
            return 2;
        }
        else if(i < 24){
            return 3;
        }
        else {
            return 4;
        }
    }

    int minimumPushes(string word) {
        int ans = 0;
        for(int i=0;i<word.size();i++){
            ans += getValue(i);
        }
        return ans;
    }
};