class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;

        for(int i=0;i<n;i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int maxi = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(heights));
        }
        return maxi;
    }
};