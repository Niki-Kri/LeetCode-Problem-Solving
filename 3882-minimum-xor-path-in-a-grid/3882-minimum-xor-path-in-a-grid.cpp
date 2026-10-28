class Solution {
public:
    int minCost(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<char>>> dp(m,vector<vector<char>>(n,vector<char>(1024,0)));
        dp[0][0][grid[0][0]]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                for(int v=0;v<1024;v++){
                    if((i>0&&dp[i-1][j][v])||(j>0&&dp[i][j-1][v]))
                        dp[i][j][v^grid[i][j]]=1;
                }
            }
        }
        for(int v=0;v<1024;v++)
            if(dp[m-1][n-1][v])return v;
        return 0;
    }
};