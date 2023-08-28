class MyStack {
private:
    queue<int> q;
    int back;
public:
    MyStack() {
        q = queue<int>();
    }
    
    void push(int x) {
        q.push(x);
        back = x;
    }
    
    int pop() {
        if (empty()) return NULL;
        int n = q.size() - 1;
        while (n-- > 0) {
            q.push(q.front());
            back = q.front();
            q.pop();
        }
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if (empty()) return NULL;
        return back;
    }
    
    bool empty() {
        return q.empty();
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