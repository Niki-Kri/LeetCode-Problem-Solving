class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val=nums[0];
        int total_moves=0;
        for(int num:nums){
            if(num>max_val){
                max_val=num;
            }
        }
        for(int num:nums){
            total_moves+=(max_val-num);
        }
        return total_moves;
    }
};