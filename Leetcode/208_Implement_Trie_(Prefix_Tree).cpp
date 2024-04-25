class Trie {
public:
    map<string, int> w, pf;

    Trie() {
        w.clear();
        pf.clear();
    }
    
    void insert(string word) {
        w[word]++;
        string str = "";
        for (int i = 0; i < word.size(); i++) {
            str += word[i];
            pf[str]++;
        }
    }
    
    bool search(string word) {
        return w[word] > 0 ? true : false;
    }
    
    bool startsWith(string prefix) {
        return pf[prefix] > 0 ? true : false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */