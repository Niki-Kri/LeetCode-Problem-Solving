class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    void makeCombinations(int start, int n, int k) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (int i = start; i <= n; i++) {
            current.push_back(i);           
            makeCombinations(i + 1, n, k);  
            current.pop_back();             
        }
    }
    vector<vector<int>> combine(int n, int k) {
        makeCombinations(1, n, k);
        return result;
    }
};