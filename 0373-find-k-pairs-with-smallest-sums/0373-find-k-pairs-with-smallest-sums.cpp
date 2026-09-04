class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result;
        }
        auto comp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        int n1 = nums1.size();
        for (int i = 0; i < min(n1, k); ++i) {
            minHeap.push({i, 0});
        }
        while (k > 0 && !minHeap.empty()) {
            auto [i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                minHeap.push({i, j + 1});
            }  
            k--;
        }
        return result;
    }
};