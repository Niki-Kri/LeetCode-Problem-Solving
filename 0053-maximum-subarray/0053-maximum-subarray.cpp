class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int current_max = nums[0];
        int global_max = nums[0];
        int n = nums.size(); 
        for(int i = 1; i<n; i++){
            if(current_max<0){
                current_max = 0;
            }
            current_max += nums[i];
            if(current_max>global_max){
                global_max = current_max;
            }
        }
        return global_max;
    }
};