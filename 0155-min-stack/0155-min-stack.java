class MinStack {
    ArrayList<Integer>st  = new ArrayList<>();

    public MinStack() {
        
    }
    
    public void push(int val) {
        st.add(val);   
    }
    
    public void pop() {
        st.remove(st.size()-1);
        
    }
    
    public int top() {
        return st.get(st.size()-1); 
    }
    
    public int getMin() {
        int val = Collections.min(st);
        return val;
        
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */