class MyCircularDeque {
private:
    deque<int> d;
    int k;
public:
    MyCircularDeque(int k) {
        d.clear();
        this->k = k;
    }
    
    bool insertFront(int value) {
        if (d.size() >= k) return false;
        d.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if (d.size() >= k) return false;
        d.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (d.size() == 0) return false;
        d.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if (d.size() == 0) return false;
        d.pop_back();
        return true;
    }
    
    int getFront() {
        return d.size() == 0 ? -1 : d.front();
    }
    
    int getRear() {
        return d.size() == 0 ? -1 : d.back();
    }
    
    bool isEmpty() {
        return d.size() == 0;
    }
    
    bool isFull() {
        return d.size() == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */