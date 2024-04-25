class Node {
public:
    Node* next[26];
    bool end = false;
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* ptr = root;
        for (auto c: word) {
            if (!ptr->next[c-'a']) ptr->next[c-'a'] = new Node();
            ptr = ptr->next[c-'a'];
        }
        ptr->end = true;
    }
    
    bool search(string word) {
        Node* ptr = root;
        for (auto c: word) {
            if (!ptr->next[c-'a']) return false;
            ptr = ptr->next[c-'a'];
        }
        return ptr->end ? true : false;
    }
    
    bool startsWith(string prefix) {
        Node* ptr = root;
        for (auto c: prefix) {
            if(!ptr->next[c-'a']) return false;
            ptr = ptr->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */