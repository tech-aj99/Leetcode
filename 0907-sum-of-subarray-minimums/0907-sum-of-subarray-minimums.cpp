class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // Find previous smaller
        for(int i=0;i<n;i++){
            // Remove greater element
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            // Distance from previous smaller
            if(st.empty()){
                left[i] = i + 1;
            }
            else{
                left[i] = i - st.top();
            }
            // Store Index
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Find next smaller
        for(int i = n-1;i>=0;i--){
            // Remove greater/equal elements
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            // Distance from next smaller
            if(st.empty()){
                right[i] = n - i;
            }
            else{
                right[i] = st.top() - i;
            }
            // Store Index
            st.push(i);
        }

        long long ans = 0;

        // Add each element's contribution
        for(int i=0;i<n;i++){
            ans = (ans + 1LL * arr[i] * left[i] * right[i]) % MOD;
        }
        return ans;
    }
};