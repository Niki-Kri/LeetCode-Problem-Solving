struct TrieNode {
    TrieNode* next[26] = {};
    string* word = nullptr;
};
class Solution {
    void dfs(vector<vector<char>>& b, int i, int j, TrieNode* p, vector<string>& res) {
        if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] == '#' || !p->next[b[i][j] - 'a']) return;
        char c = b[i][j];
        p = p->next[c - 'a'];
        if (p->word) {
            res.push_back(*p->word);
            p->word = nullptr; 
        }
        b[i][j] = '#';
        dfs(b, i + 1, j, p, res);
        dfs(b, i - 1, j, p, res);
        dfs(b, i, j + 1, p, res);
        dfs(b, i, j - 1, p, res);
        b[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (auto& w : words) {
            TrieNode* p = &root;
            for (char c : w) {
                if (!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->word = &w;
        }
        vector<string> res;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, &root, res);
            }
        }
        return res;
    }
};