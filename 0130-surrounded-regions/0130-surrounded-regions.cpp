class Solution {
    void dfs(vector<vector<char>>& b, int i, int j) {
        if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() || b[i][j] != 'O') return;
        b[i][j] = 'T';
        dfs(b, i + 1, j);
        dfs(b, i - 1, j); 
        dfs(b, i, j + 1); 
        dfs(b, i, j - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            dfs(board, i, 0), dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++){
            dfs(board, 0, j), dfs(board, m - 1, j);
        } 
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                board[i][j] = (board[i][j] == 'T') ? 'O' : 'X';
            }
        }
    }
};