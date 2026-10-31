class Solution {
private:
    pair<pair<int,int>,bool> simulate(int r,int c,int dir,const vector<vector<int>>& grid,int m,int n){
        while(true){
            int nr=r,nc=c;
            if(dir==0)nc++;
            else nr++;

            if(nr<0||nr>=m||nc<0||nc>=n){
                return {{-1,-1},false};
            }
            if(grid[nr][nc]== 1){
                if(dir==0){
                    r=nr;c=nc;dir=1;
                }else{
                    r=nr;c=nc;dir=0;
                }
            }else{
                return {{nr,nc},true};
            }
        }
    }

public:
    int uniquePaths(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        long long MOD=1e9+7;

        vector<vector<long long>> dp(m,vector<long long>(n,0));
        dp[0][0]=1;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(dp[r][c]==0)continue;
                pair<pair<int,int>,bool> result_right=simulate(r,c,0,grid,m,n);
                if(result_right.second){
                    int tr=result_right.first.first;
                    int tc=result_right.first.second;
                    dp[tr][tc]=(dp[tr][tc]+dp[r][c])%MOD;
                }
                pair<pair<int,int>,bool> result_down=simulate(r,c,1,grid,m,n);
                if(result_down.second){
                    int tr=result_down.first.first;
                    int tc=result_down.first.second;
                    dp[tr][tc]=(dp[tr][tc]+dp[r][c])%MOD;
                }
            }
        }
        return dp[m-1][n-1];
    }
};