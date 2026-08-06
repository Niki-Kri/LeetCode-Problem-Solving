class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int fact = 1;
        for (int i = 1; i <= n; i++) fact *= i;
        res.reserve(fact);
        function<void(int)> bt = [&](int start) {
            if (start == n) {
                res.push_back(nums);
                return;
            }
            for (int i = start; i < n; i++) {
                swap(nums[start], nums[i]);
                bt(start + 1);
                swap(nums[start], nums[i]);
            }
        };
        bt(0);
        return res;
    }
};