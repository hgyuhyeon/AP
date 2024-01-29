class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    
    void push(int x) {
        s1.push(x);
    }

    void move() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        if (s2.empty()) move();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (s2.empty()) move();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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