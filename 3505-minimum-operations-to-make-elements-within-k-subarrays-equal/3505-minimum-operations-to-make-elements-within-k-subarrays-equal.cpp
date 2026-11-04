class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        const long long INF=1e18;
        multiset<int> low, high;
        long long lowSum=0, highSum=0;
        vector<long long> windowCost(n-x+1);
        int lowSize=(x+1)/2;

        auto balance=[&](){
            while((int)low.size()>lowSize){
                int v =* low.rbegin();
                low.erase(prev(low.end()));
                lowSum -= v;
                high.insert(v);
                highSum+=v;
            }
            while((int)low.size()<lowSize&&!high.empty()){
                int v=*high.begin();
                high.erase(high.begin());
                highSum -= v;
                low.insert(v);
                lowSum += v;
            }
        };

        auto addNumber=[&](int v){
            if(low.empty()||v <= *low.rbegin()){
                low.insert(v);
                lowSum+=v;
            }
            else{
                high.insert(v);
                highSum+=v;
            }
            balance();
        };

        auto removeNumber=[&](int v){
            auto it=low.find(v);
            if(it != low.end()){
                low.erase(it);
                lowSum-=v;
            }
            else{
                high.erase(high.find(v));
                highSum-=v;
            }
            balance();
        };

        for(int i=0;i<n;i++){
            addNumber(nums[i]);
            if(i >= x)removeNumber(nums[i-x]);
            if(i >= x-1){
                long long median=*low.rbegin();
                long long cost=median*(long long)low.size()-lowSum+highSum-median*(long long)high.size();
                windowCost[i-x+1]=cost;
            }
        }

        vector<vector<long long>> dp(k+1,vector<long long>(n+1,INF));
        for(int i=0;i<=n;i++)dp[0][i]=0;
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                dp[j][i]=dp[j][i-1];
                if(i>=x&&dp[j-1][i-x]!=INF){
                    dp[j][i]=min(dp[j][i],dp[j-1][i-x]+windowCost[i-x]);
                }
            }
        }
        return dp[k][n];
    }
};