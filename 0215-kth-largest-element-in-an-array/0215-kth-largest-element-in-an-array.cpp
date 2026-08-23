class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int counts[20001] = {0};
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            counts[num + 10000] = counts[num + 10000] + 1;
        }
        for (int i = 20000; i >= 0; i--) {
            k = k - counts[i];
            if (k <= 0) {
                return i - 10000;
            }
        }
        return 0; 
    }
};