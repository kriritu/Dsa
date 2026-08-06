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

    long long sumSubarrayMins(vector<int>& arr) {
        vector <int> nse= FindNSE(arr);
        vector<int> pse = FindPSE(arr);
        int n = arr.size();
        long long  total = 0;
        //long long modulo = 1e9+7;

        for(int i = 0; i<n; i++){
            long long left = i - pse[i];
            long long right = nse[i] -i;

            total += (left*right* arr[i]);

        }
        return total;

    }
    vector<int> FindNGE(vector<int>&arr){
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            nge[i] = st.empty()? n :st.top();
            st.push(i);

        }
        return nge;
    }
    vector<int> FindPGE(vector<int>&arr){
    
        int n = arr.size();
        vector<int>  pge(n);
        stack<int> st;

        for(int i= 0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);

        }
        return pge;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector <int> nge= FindNGE(arr);
        vector<int> pge = FindPGE(arr);
        int n = arr.size();
        long long  total = 0;
        //long long modulo = 1e9+7; no need of modulo here 

        for(int i = 0; i<n; i++){
            long long left = i - pge[i];
            long long right = nge[i] -i;

            total += (left*right* arr[i]);
            
        }
        return total;

    }
    long long subArrayRanges(vector<int>& nums) {
        return  sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        
        
        
    }
};