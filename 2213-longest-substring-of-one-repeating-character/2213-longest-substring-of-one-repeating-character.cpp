class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        // set of intervals: {start, end}
        set<pair<int,int>> st;

        // lengths of all groups
        multiset<int> len;

        // Create initial groups
        for (int i = 0; i < n; ) {

            int j = i;

            while (j + 1 < n && s[j + 1] == s[i])
                j++;

            st.insert({i, j});
            len.insert(j - i + 1);

            i = j + 1;
        }

        vector<int> ans;

        for (int q = 0; q < queryIndices.size(); q++) {

            int pos = queryIndices[q];
            char ch = queryCharacters[q];

            if (s[pos] == ch) {
                ans.push_back(*len.rbegin());
                continue;
            }

            // Find group containing pos
            auto it = st.upper_bound({pos, n});

            --it;

            int l = it->first;
            int r = it->second;

            // Remove old group
            len.erase(len.find(r - l + 1));
            st.erase(it);

            // Left part
            if (l <= pos - 1) {
                st.insert({l, pos - 1});
                len.insert(pos - l);
            }

            // Right part
            if (pos + 1 <= r) {
                st.insert({pos + 1, r});
                len.insert(r - pos);
            }

            s[pos] = ch;

            // Add new character as a group
            int nl = pos;
            int nr = pos;

            // Merge with left group
            auto rightIt = st.lower_bound({pos, pos});

            if (rightIt != st.begin()) {
                auto leftIt = prev(rightIt);

                if (s[leftIt->second] == ch) {
                    nl = leftIt->first;

                    len.erase(len.find(leftIt->second -
                                       leftIt->first + 1));

                    st.erase(leftIt);
                }
            }

            // Merge with right group
            auto nextIt = st.lower_bound({pos + 1, pos + 1});

            if (nextIt != st.end()) {
                if (s[nextIt->first] == ch) {
                    nr = nextIt->second;

                    len.erase(len.find(nextIt->second -
                                       nextIt->first + 1));

                    st.erase(nextIt);
                }
            }

            st.insert({nl, nr});
            len.insert(nr - nl + 1);

            ans.push_back(*len.rbegin());
        }

        return ans;
    }
};