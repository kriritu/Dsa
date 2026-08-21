class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea =0;
        int nse;
        int pse;
        int element;

        for(int i =0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty()? -1 : st.top();
                maxArea = max((heights[element] * (nse-pse-1)) , maxArea);
                
            }
            st.push(i); 
        }
        while(!st.empty()){
            nse = heights.size();
            element = st.top();
            st.pop();
            pse = st.empty()? -1 : st.top();
            maxArea = max((heights[element] * (nse-pse-1)) , maxArea);

        }
        return maxArea; 
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()  || matrix[0].empty()) return 0;
        int maxArea = 0;
        int rows = matrix.size();
        int col = matrix[0].size();
        int sum =0;
        vector<int> prefixsum(col, 0);

        for(int  r=0; r< rows; r++){
            for(int c=0; c< col; c++){
                sum+= matrix[r][c];
                if(matrix[r][c] == '1') prefixsum[c] += 1;
                else prefixsum[c] = 0;
    
            }
            maxArea = max(maxArea, largestRectangleArea(prefixsum));
        }
        return maxArea;

    }
};