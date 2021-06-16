class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        int x;
    }
    stack<int> s1;
    stack<int> s2;
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty())
        {
            int y = s1.top();
            s1.pop();
            s2.push(y);
        }
        s1.push(x);
        while(!s2.empty())
        {
            int y = s2.top();
            s2.pop();
            s1.push(y);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        int res = s1.top();
        s1.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */