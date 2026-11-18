class Solution {
    unordered_map<int, vector<int>> m;
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
    }
    int pick(int target) {
        vector<int>& idx=m[target];
        int r=rand() % idx.size();
        return idx[r];
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */