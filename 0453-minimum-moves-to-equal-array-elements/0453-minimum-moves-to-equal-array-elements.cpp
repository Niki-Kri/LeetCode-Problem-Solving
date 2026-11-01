class Solution {
public:
    int minMoves(vector<int>& nums) {
        int smallest=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<smallest){
                smallest=nums[i];
            }
        }
        int totalMoves=0;
        for(int i=0;i<nums.size();i++){
            totalMoves+=(nums[i]-smallest);
        }
        return totalMoves;
    }
};