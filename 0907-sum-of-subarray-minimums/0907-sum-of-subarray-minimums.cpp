class Solution {
public:
    vector<int> FindNSE(vector<int>&arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty()? n :st.top();
            st.push(i);

        }
        return nse;
    }

    vector<int> FindPSE(vector<int>&arr){
    
        int n = arr.size();
        vector<int>  pse(n);
        stack<int> st;

        for(int i= 0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);

        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector <int> nse= FindNSE(arr);
        vector<int> pse = FindPSE(arr);
        int n = arr.size();
        long long  total = 0;
        long long modulo = 1e9+7;

        for(int i = 0; i<n; i++){
            long long left = i - pse[i];
            long long right = nse[i] -i;

            long long multiply = (left*right)% modulo;
            long long ans =(multiply * arr[i]) % modulo;
            total = (total+ ans) % modulo; 
            
        }
        return total;

    }
};