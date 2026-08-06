class Solution {
    const string pad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(const string& digits, int pos, string& current, vector<string>& res) {
        if (pos == digits.size()) {
            res.push_back(current);
            return;
        }
        for (char c : pad[digits[pos] - '0']) {
            current.push_back(c);
            backtrack(digits, pos + 1, current, res);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string current;
        current.reserve(digits.size());
        backtrack(digits, 0, current, res);
        return res;
    }
};