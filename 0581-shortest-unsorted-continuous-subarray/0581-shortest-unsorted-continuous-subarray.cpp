class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0],r=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<mx) r=i;
            else mx=nums[i];
        }
        int mn=nums[n-1],l=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>mn) l=i;
            else mn=nums[i];
        }
        if(r==-1) return 0;
        return r-l+1;
    }
};