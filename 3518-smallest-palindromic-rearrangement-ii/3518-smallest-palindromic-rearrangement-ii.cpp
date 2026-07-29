class Solution {
public:
    long long countWays(vector<int> &freq, long long k){
        long long ways = 1;
        int used = 0;

        for(int x : freq){
            for(int j=1;j<=x;j++){
                used++;
                ways = ways * used / j;

                if(ways >= k){
                    return k;
                }
            }
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for(char ch : s){
            freq[ch - 'a']++;
        }

        char mid = 0;

        for(int i=0;i<26;i++){
            if(freq[i] % 2){
                mid = 'a' + i;
            }
            freq[i] /= 2;
        }

        string left;
        while(left.size() < s.size()/2){
            bool found = false;

            for(int i=0;i<26;i++){
                if(freq[i] == 0){
                    continue;
                }
                freq[i]--;
                long long ways = countWays(freq, k);

                if(ways >= k){
                    left += 'a' + i;
                    found = true;
                    break;
                }
                k -= ways;
                freq[i]++;
            }
            if(!found){
                return "";
            }
        }
        string right = left;
        reverse(right.begin(), right.end());

        return left+(mid ? string(1, mid) : "")+right;
    }
};