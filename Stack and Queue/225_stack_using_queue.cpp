class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        int x;
      
    }
     queue<int> q1;
     queue<int> q2;
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        q2.push(x);
        while(!q1.empty())
        {
            int top= q1.front();
            q1.pop();
            q2.push(top);
       }
            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
       int top= q1.front();
        q1.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
       return q1.front();
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */