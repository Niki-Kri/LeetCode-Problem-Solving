class Solution{
    long long dp[15][15];
    long long getMaxPaths(const vector<string>& grid,int m,int n){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='#'){
                    dp[i][j]=0;
                    continue;
                }
                if(i>0) dp[i][j]+=dp[i-1][j];
                if(j>0) dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    bool dfs(int idx,vector<string>& grid,int m,int n,int k){
        if(idx==m*n){
            return getMaxPaths(grid,m,n)==k;
        }
        int r=idx/n;
        int c=idx%n;
        if((r==0&&c==0)||(r==m-1&&c==n-1)){
            return dfs(idx+1,grid,m,n,k);
        }
        grid[r][c]='#';
        if(getMaxPaths(grid,m,n)>=k){
            if(dfs(idx+1,grid,m,n,k)) return true;
        }
        grid[r][c]='.';
        if(getMaxPaths(grid,m,n)>=k){
            if(dfs(idx+1,grid,m,n,k)) return true;
        }
        return false;
    } 
public:
    vector<string> createGrid(int m,int n,int k){
        vector<string> grid(m,string(n,'.'));
        if(getMaxPaths(grid,m,n)<k) return {};
        if(dfs(0,grid,m,n,k)){
            return grid;
        }
        return {};
    }
};