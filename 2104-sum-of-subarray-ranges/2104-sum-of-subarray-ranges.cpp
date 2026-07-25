class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long minsum = 0, maxsum = 0;

        vector<int> left(n), right(n);
        stack<int> st;

        // Minimum
        // Previous smaller
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() -i;
            st.push(i);
        }

        for(int i=0;i<n;i++){
            minsum += 1LL * nums[i] * left[i] * right[i];
        }

        // ---------- Maximum ----------

        while(!st.empty()) st.pop();

        // Previous greater
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next greater
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        for(int i = 0; i < n; i++)
            maxsum += 1LL * nums[i] * left[i] * right[i];

        return maxsum - minsum;
    }
};