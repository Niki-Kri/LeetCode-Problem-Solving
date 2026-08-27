class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(0, t, c, cur, res);
        return res;
    }
private:
    void dfs(int i, int t, vector<int>& c, vector<int>& cur, vector<vector<int>>& res) {
        if (t == 0) {
            res.push_back(cur);
            return;
        }
        if (t < 0 || i >= c.size()) {
            return;
        }
        cur.push_back(c[i]);
        dfs(i, t - c[i], c, cur, res);
        cur.pop_back();
        dfs(i + 1, t, c, cur, res);
    }
};