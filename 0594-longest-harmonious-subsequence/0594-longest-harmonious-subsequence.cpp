class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x: nums) {
            freq[x]++;
        }
        int max_len=0;
        for(auto pair: freq) {
            int val=pair.first;
            int count=pair.second;
            if(freq.count(val+1)) {
                max_len=max(max_len, count+freq[val+1]);
            }
        }
        return max_len;
    }
};