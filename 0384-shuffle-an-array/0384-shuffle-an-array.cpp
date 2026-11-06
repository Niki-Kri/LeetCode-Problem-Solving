class Solution {
private:
    vector<int> original;
    vector<int> current;

public:
    Solution(vector<int>& nums) {
        original=nums;
        current=nums;
    }
    vector<int> reset() {
        current = original;
        return current;
    }
    vector<int> shuffle() {
        for (int i=0;i<current.size();i++) {
            int ranIndex = rand()%current.size();
            int temp = current[i];
            current[i]=current[ranIndex];
            current[ranIndex] = temp;
        }
        return current;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */