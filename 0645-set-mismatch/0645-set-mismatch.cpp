class Solution {
public:

    // APPROACH 1: Using Frequency Array (commented out)
    // vector<int> findErrorNums(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> freq(n + 1, 0);
    //     int dup = -1, miss = -1;
    //     for (int x : nums) freq[x]++;
    //     for (int i = 1; i <= n; i++) {
    //         if (freq[i] == 2) dup = i;
    //         if (freq[i] == 0) miss = i;
    //     }
    //     return {dup, miss};
    // }

    // APPROACH 2: Using Boolean Array
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();
        vector<bool> isPresent(n + 1, false);

        // First loop: find the duplicate
        for (int i = 0; i < n; i++) {
            if (isPresent[nums[i]]) {
                ans.push_back(nums[i]);
            }
            isPresent[nums[i]] = true;
        }

        // Second loop: find the missing number
        for (int i = 1; i < isPresent.size(); i++) {
            if (!isPresent[i]) {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};