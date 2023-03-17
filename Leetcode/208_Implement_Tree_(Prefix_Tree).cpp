class Trie {
public:
    map<string, int> s, pf;
    
    Trie() {
        s.clear();
        pf.clear();
    }
    
    void insert(string word) {
        s[word]++;
        string str = "";
        for (auto c: word) {
            str += c;
            pf[str]++;
        }
    }
    
    bool search(string word) {
        if (s[word]) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        if (pf[prefix]) return true;
        else return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */