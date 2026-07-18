class MinStack {
public:
    long long mini = INT_MAX;
    stack<long long > st;
    MinStack() {
          
    }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            if(value >= mini) st.push(value);
            else{
                long long pushelement = 2LL *value - mini;
                st.push(pushelement);
                mini = value;
            }
           
        }
        
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini){
            mini = 2*mini -x;
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top(); 
        if(mini < x) return x;
        else return mini;
        
    }
    
    int getMin() {
        return mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */