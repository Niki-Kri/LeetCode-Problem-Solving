class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            dp[x+1]=max(dp[x+1],dp[x]+1);
            dp[x]=max(dp[x],dp[x-1]+1);
            ans=max({ans,dp[x],dp[x+1]});
        }
        return ans;
    }
};