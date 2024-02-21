class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        return s.insert(val).second;
    }
    
    bool remove(int val) {
        return s.erase(val);
    }
    
    int getRandom() {
        int num = rand() % s.size(), cnt = 0;
        for (auto itr = s.begin(); itr != s.end(); itr++) if (cnt++ == num) return *itr;
        return *s.begin();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */