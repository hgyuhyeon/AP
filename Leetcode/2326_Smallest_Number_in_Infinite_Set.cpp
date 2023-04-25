class SmallestInfiniteSet {
public:
    vector<int> v;
    SmallestInfiniteSet() {
        v = vector<int>(1001, true);
    }
    
    int popSmallest() {
        for (int i = 1; i <= 1000; i++) {
            if (v[i]) {
                v[i] = false;
                return i;
            }
        }
        return 0;
    }
    
    void addBack(int num) { 
        v[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */