class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=0;
        for(int x:nums){
            totalSum+=x;
        }
        if((totalSum+target)%2!=0||totalSum<abs(target)){
            return 0;
        }
        int s=(totalSum+target)/2;
        vector<int> dp(s+1,0);
        dp[0]=1;
        for(int x:nums){
            for(int j=s;j>=x;j--){
                dp[j]=dp[j]+dp[j-x];
            }
        }
        return dp[s];
    }
};