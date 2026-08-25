class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int curr_max = 0;
        int max_sum = nums[0];
        int curr_min = 0;
        int min_sum = nums[0];
        for (int num : nums) {
            curr_max = max(num, curr_max + num);
            max_sum = max(max_sum, curr_max);
            curr_min = min(num, curr_min + num);
            min_sum = min(min_sum, curr_min);
            total_sum += num;
        }
        if (max_sum > 0) {
            return max(max_sum, total_sum - min_sum);
        } else {
            return max_sum;
        }
    }
};