class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '1';
                int bit = 1 << num;
                int b = (i / 3) * 3 + (j / 3);
                if (rows[i] & bit) return false;
                if (cols[j] & bit) return false;
                if (boxes[b] & bit) return false;
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[b] |= bit;
            }
        }
        return true;
    }
};