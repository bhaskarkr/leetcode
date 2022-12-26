class Node {
public:
    vector<Node*> children;
    bool isWord;
    Node() {
        isWord = false;
        children = vector<Node*>(26, NULL);
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for(char c : word) {
            if(!curr->children[c-'a'])
                curr->children[c-'a'] = new Node();
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node *curr = root;
        for(char c : word) {
            if(!curr->children[c-'a'])
                return false;
            curr = curr->children[c-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root, *prev = root;
        for(char c : prefix) {
            if(!curr->children[c-'a'])
                return false;
            curr = curr->children[c-'a'];
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
