class Solution {
public:

    vector<int> getFactorCount(long long t) {
        vector<int> cnt(4, 0);
        int primes[] = {2, 3, 5, 7};

        for(int i = 0; i < 4; i++) {
            while(t % primes[i] == 0) {
                cnt[i]++;
                t /= primes[i];
            }
        }

        if(t != 1)
            return {};

        return cnt;
    }

    string construct(vector<int> cnt) {
        int c2 = cnt[0];
        int c3 = cnt[1];
        int c5 = cnt[2];
        int c7 = cnt[3];

        int c8 = c2 / 3;
        c2 %= 3;

        int c9 = c3 / 2;
        c3 %= 2;

        int c4 = c2 / 2;
        c2 %= 2;

        int c6 = 0;

        if(c2 == 1 && c3 == 1) {
            c2 = 0;
            c3 = 0;
            c6 = 1;
        }

        if(c3 == 1 && c4 == 1) {
            c3 = 0;
            c4 = 0;
            c2 = 1;
            c6 = 1;
        }

        string ans;

        ans += string(c2, '2');
        ans += string(c3, '3');
        ans += string(c4, '4');
        ans += string(c5, '5');
        ans += string(c6, '6');
        ans += string(c7, '7');
        ans += string(c8, '8');
        ans += string(c9, '9');

        return ans;
    }

    int countDigits(vector<int> cnt) {
        int c2 = cnt[0];
        int c3 = cnt[1];

        int c8 = c2 / 3;
        c2 %= 3;

        int c9 = c3 / 2;
        c3 %= 2;

        int c4 = c2 / 2;
        c2 %= 2;

        int c6 = 0;

        if(c2 == 1 && c3 == 1) {
            c2 = 0;
            c3 = 0;
            c6 = 1;
        }

        if(c3 == 1 && c4 == 1) {
            c3 = 0;
            c4 = 0;
            c2 = 1;
            c6 = 1;
        }

        return c2 + c3 + c4 + cnt[2] + c6 + cnt[3] + c8 + c9;
    }

    vector<int> subtract(vector<int> a, vector<int> b) {
        for(int i = 0; i < 4; i++) {
            a[i] = max(0, a[i] - b[i]);
        }

        return a;
    }

    vector<int> digitFactors(int d) {
        vector<int> f(4, 0);

        if(d == 2) f[0] = 1;
        if(d == 3) f[1] = 1;
        if(d == 4) f[0] = 2;
        if(d == 5) f[2] = 1;

        if(d == 6) {
            f[0] = 1;
            f[1] = 1;
        }

        if(d == 7) f[3] = 1;
        if(d == 8) f[0] = 3;
        if(d == 9) f[1] = 2;

        return f;
    }

    bool enough(vector<int> need, vector<int> have) {
        for(int i = 0; i < 4; i++) {
            if(have[i] < need[i])
                return false;
        }

        return true;
    }

    string smallestNumber(string num, long long t) {
        vector<int> need = getFactorCount(t);

        if(need.empty())
            return "-1";

        int n = num.size();

        int requiredDigits = countDigits(need);

        if(requiredDigits > n)
            return construct(need);

        vector<int> total(4, 0);

        int firstZero = n;

        for(int i = 0; i < n; i++) {
            if(num[i] == '0' && firstZero == n)
                firstZero = i;

            vector<int> f = digitFactors(num[i] - '0');

            for(int j = 0; j < 4; j++)
                total[j] += f[j];
        }

        if(firstZero == n && enough(need, total))
            return num;

        vector<int> prefix = total;

        for(int i = n - 1; i >= 0; i--) {
            int currentDigit = num[i] - '0';

            vector<int> curFactors = digitFactors(currentDigit);

            for(int j = 0; j < 4; j++)
                prefix[j] -= curFactors[j];

            if(i > firstZero)
                continue;

            for(int digit = currentDigit + 1; digit <= 9; digit++) {
                vector<int> digitF = digitFactors(digit);

                vector<int> remaining = need;

                for(int j = 0; j < 4; j++) {
                    remaining[j] =
                        max(0, need[j] - prefix[j] - digitF[j]);
                }

                int digitsNeeded = countDigits(remaining);
                int space = n - i - 1;

                if(digitsNeeded <= space) {
                    string ans = num.substr(0, i);

                    ans += char('0' + digit);
                    ans += string(space - digitsNeeded, '1');
                    ans += construct(remaining);

                    return ans;
                }
            }
        }

        vector<int> remaining = need;

        int digitsNeeded = countDigits(remaining);

        string ans;

        ans += string(n + 1 - digitsNeeded, '1');
        ans += construct(remaining);

        return ans;
    }
};