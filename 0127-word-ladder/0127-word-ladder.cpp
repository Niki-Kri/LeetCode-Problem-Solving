class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        unordered_set<string> beginSet;
        unordered_set<string> endSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int length = 1;
        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
            unordered_set<string> nextSet;
            for (string word : beginSet) {
                for (int i = 0; i < word.size(); ++i) {
                    char originalChar = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (originalChar == c) continue;
                        word[i] = c; 
                        if (endSet.find(word) != endSet.end()) {
                            return length + 1;
                        }
                        if (dict.find(word) != dict.end()) {
                            nextSet.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = originalChar;
                }
            }
            beginSet = nextSet;
            length++;
        }
        return 0;
    }
};