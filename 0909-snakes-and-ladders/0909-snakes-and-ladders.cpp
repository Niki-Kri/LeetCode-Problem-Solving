class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == n * n) {
                return dist[curr];
            }
            for (int i = 1; i <= 6; ++i) {
                int next_sq = curr + i;
                if (next_sq > n * n) break;
                int idx = next_sq - 1;
                int r = n - 1 - (idx / n);
                int c = idx % n;
                if ((idx / n) % 2 != 0) {
                    c = n - 1 - c;
                }
                int dest = (board[r][c] == -1) ? next_sq : board[r][c];
                if (dist[dest] == -1) {
                    dist[dest] = dist[curr] + 1;
                    q.push(dest);
                }
            }
        }
        return -1;
    }
};