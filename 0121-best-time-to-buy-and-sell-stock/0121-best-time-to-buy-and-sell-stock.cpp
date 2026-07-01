class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=0;
        int min_price=prices[0];
        for(int i=1;i<n;i++){
            int curr_profit=prices[i]-min_price;
            if(curr_profit > max_profit){
                max_profit=curr_profit;
            }
            min_price=min(min_price,prices[i]);
        }
        return max_profit;
    }
};