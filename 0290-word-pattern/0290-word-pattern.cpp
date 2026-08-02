class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> charToWord(26, "");
        unordered_set<string> mappedWords;
        stringstream ss(s);
        string word;
        int i = 0;
        int n = pattern.length();
        while (ss >> word) {
            if (i == n) {
                return false;
            }
            char c = pattern[i];
            if (charToWord[c - 'a'] == "") {
                if (mappedWords.count(word)) {
                    return false; 
                }
                charToWord[c - 'a'] = word;
                mappedWords.insert(word);
            } else {
                if (charToWord[c - 'a'] != word) {
                    return false;
                }
            }
            i++;
        }
        return i == n;
    }
};