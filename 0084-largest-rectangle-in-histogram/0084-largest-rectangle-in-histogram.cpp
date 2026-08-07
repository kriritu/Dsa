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
                int element = st.top();
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
};