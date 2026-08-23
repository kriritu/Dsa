class Solution {
public:

    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        stack<int> st;

        for(int i =0; i< num.size(); i++){
            while(!st.empty() && num[st.top()] > num[i] && k>0){
                st.pop();
                k= k-1;
            }
            st.push(i);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string result;
        while(!st.empty()){
            result.push_back(num[st.top()]);
            st.pop();
        }
        reverse(result.begin(), result.end());
        int i = 0;
        while(i< result.size()-1 && result[i] == '0'){
            i++;
            
        }
        result = result.substr(i);
        return result.empty()? "0": result;
        
    }
};