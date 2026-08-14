class Solution {
public:
    vector<string> res; 
    void f(int n, int o, int c, string s) {
        if (s.length() == n * 2) {
            res.push_back(s);
            return;
        }
        if (o < n) {
            f(n, o + 1, c, s + "(");
        }
        if (c < o) {
            f(n, o, c + 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        res.clear(); 
        f(n, 0, 0, "");
        return res;
    }
};