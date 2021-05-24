class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> a,b;
    MinStack() {
        a = b = {};
        
    }
    
    void push(int val) {
        a.push_back(val);
        if(b.empty()) b.push_back(val);
        else {
            int newMin = min(val,*b.rbegin());
            b.push_back(newMin);
        }
        
    }
    
    void pop() {
        a.pop_back();
        b.pop_back();
        
    }
    
    int top() {
        return *a.rbegin();
        
    }
    
    int getMin() {
        return *b.rbegin();
        
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