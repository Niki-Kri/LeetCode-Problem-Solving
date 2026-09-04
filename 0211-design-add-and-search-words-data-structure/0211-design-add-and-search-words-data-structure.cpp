class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isWord = false;
    };
    TrieNode* root;
    bool searchHelper(const string& word, int index, TrieNode* node) {
        for (int i = index; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] && searchHelper(word, i + 1, node->children[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                int childIdx = c - 'a';
                if (!node->children[childIdx]) {
                    return false;
                }
                node = node->children[childIdx];
            }
        }
        return node->isWord;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};