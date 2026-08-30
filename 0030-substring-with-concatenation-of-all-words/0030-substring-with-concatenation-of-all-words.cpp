class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.length();
        if (n < totalLen) return result;
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> windowCount;
            int left = i;
            int count = 0; 
            for (int j = i; j <= n - wordLen; j += wordLen) {
                string currentWord = s.substr(j, wordLen);
                if (wordCount.count(currentWord)) {
                    windowCount[currentWord]++;
                    count++;
                    while (windowCount[currentWord] > wordCount[currentWord]) {
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    windowCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};