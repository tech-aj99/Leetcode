class Solution {
public:
    void solve(vector<char>& s, int &l, int &r) {
        if (l >= r) return;

        swap(s[l], s[r]);
        l++;
        r--;

        solve(s, l, r);
    }

    void reverseString(vector<char>& s) {
        int n = s.size();
        
        int l = 0;
        int r = n - 1;

        solve(s, l, r);
    }
};