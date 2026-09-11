class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, currentSubset, result);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);
        for (int i=start; i<nums.size(); i++) {
            if (i>start && nums[i]==nums[i-1]) {
                continue;
            }
            currentSubset.push_back(nums[i]);
            backtrack(nums, i+1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
};