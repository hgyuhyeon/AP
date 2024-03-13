class MinStack {
public:
    stack<int> s;
    multiset<int> min;

    MinStack() {
        while (!s.empty()) s.pop();
        min.clear();
    }
    
    void push(int val) {
        s.push(val);
        min.insert(val);
    }
    
    void pop() {
        min.erase(min.find(s.top()));
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *min.begin();
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