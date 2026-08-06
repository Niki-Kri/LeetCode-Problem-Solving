class Solution {
public:
    vector<string> ans;
    string getLetters(char digit) {
        if (digit == '2') return "abc";
        if (digit == '3') return "def";
        if (digit == '4') return "ghi";
        if (digit == '5') return "jkl";
        if (digit == '6') return "mno";
        if (digit == '7') return "pqrs";
        if (digit == '8') return "tuv";
        if (digit == '9') return "wxyz";
        return "";
    }
    void solve(string digits, string temp, int index) {
        if (index == digits.length()) {
            ans.push_back(temp);
            return;
        }
        char curr_digit = digits[index];
        string letters = getLetters(curr_digit);

        for (int i = 0; i < letters.length(); i++) {
            solve(digits, temp + letters[i], index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        ans.clear();
        if (digits.length() == 0) {
            return ans;
        }
        solve(digits, "", 0);
        return ans;
    }
};