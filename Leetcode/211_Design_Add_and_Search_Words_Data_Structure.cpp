class Node {
public:
    Node* next[26];
    bool end = false;
};


class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* ptr = root;
        for (auto c: word) {
            if (!ptr->next[c-'a']) ptr->next[c-'a'] = new Node();
            ptr = ptr->next[c-'a'];
        }
        ptr->end = true;
    }
    
    bool search(string word) {
        Node* ptr = root;
        return search_help(word, 0, root);
    }

    bool search_help(string word, int i, Node* ptr) {
        while (i < word.size()) {
            if (word[i] == '.') {
                bool ret = false;
                for (auto n: ptr->next) {
                    if (n != nullptr) ret |= search_help(word, i+1, n);
                }
                return ret;
            }
            if (!ptr->next[word[i]-'a']) return false;
            ptr = ptr->next[word[i++]-'a'];
        }
        return ptr->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */