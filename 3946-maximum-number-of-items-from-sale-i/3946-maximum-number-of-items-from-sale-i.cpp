class Solution{
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget){
        int n=items.size();
        vector<int> f(n, 0);
        int mp=1e9;
        for(int i=0;i<n;i++){
            if(items[i][1] < mp)mp=items[i][1];
            for(int j=0;j<n;j++){
                if(i!=j&&items[j][0]%items[i][0]==0)f[i]++;
            }
        }
        int inf=1e9;
        vector<int> dp(budget + 1, -inf);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int w=items[i][1];
            int v=1 + f[i];
            for(int c=budget;c>=w;c--){
                if(dp[c-w]!=-inf&&dp[c-w]+v > dp[c]){
                    dp[c]=dp[c-w]+v;
                }
            }
        }
        int ans=0;
        for(int c=0;c<=budget;c++){
            if(dp[c]!=-inf){
                int cur=dp[c] + (budget-c)/mp;
                if(cur > ans)ans=cur;
            }
        }
        return ans;
    }
};