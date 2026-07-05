class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pmax=nums[0];
        int pmin=nums[0];
        int ans=pmax;
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int temp_pmax=max(curr,max(pmax*curr,pmin*curr));
            pmin=min(curr,min(pmax*curr,pmin*curr));
            pmax=temp_pmax;
            ans=max(ans,pmax);
        }
        return ans; 
    }
};