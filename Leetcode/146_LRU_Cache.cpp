class LRUCache {
public:
    vector<int> v, cnt;
    queue<int> q;
    int cap, total;

    LRUCache(int capacity) {
        q = queue<int>();
        v = vector<int>(10001, -1);
        cnt = vector<int>(10001, 0);
        cap = capacity;
        total = 0;
    }
    
    int get(int key) {
        if (cnt[key] == 0) return -1;
        else {
            if (!cnt[key]) total++;
            cnt[key]++;
            q.push(key);
            return v[key];
        }
    }
    
    void put(int key, int value) {
        if (total < cap && !cnt[key]) {
            total++;
        }
        else if(!cnt[key]) {
            while (--cnt[q.front()]) q.pop();
            q.pop();
        }
        cnt[key]++;
        q.push(key);
        v[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */