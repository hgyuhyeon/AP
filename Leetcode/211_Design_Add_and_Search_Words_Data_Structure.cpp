class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool end;
    
    TrieNode() {
        end = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* ptr = root;
        for (auto c: word) {
            if (!ptr->children[c]) ptr->children[c] = new TrieNode();
            ptr = ptr->children[c];
        }
        ptr->end = true;
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }

    bool searchWord(TrieNode* node, string word) {
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(c == '.'){
                for(auto &p: node->children)
                    if(searchWord(p.second, word.substr(i+1))) return true;
                return false;
            }
            if(node->children.count(c) == 0) return false;
            node = node->children[c];
        }
        return node->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */