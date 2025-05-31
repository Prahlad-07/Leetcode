class MinStack {
vector<int>st;
int mini=-1;
public:
    MinStack() {   
    }
    
    void push(int val) {
        st.push_back(val);
        mini=min(mini,val);
        
    }
    
    void pop() {
        st.pop_back();
        
    }
    
    int top() {
        int val = st.back();
        return val;
        
    }
    
    int getMin() {

       return *min_element(st.begin(),st.end());
        
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */