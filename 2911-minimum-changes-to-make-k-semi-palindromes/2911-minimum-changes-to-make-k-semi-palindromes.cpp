class Solution {
public:
    int minimumChanges(string s, int k) {
        int n=s.length();
        vector<vector<int>> c(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len=j-i+1;
                int mn=1e9;
                for(int d=1;d<len;d++){
                    if(len%d==0){
                        int cur=0;
                        for(int g=0;g<d;g++){
                            for(int st=i+g,en=i+len-d+g;st<en;st+=d,en-=d){
                                if(s[st]!=s[en]) cur++;
                            }
                        }
                        mn=min(mn,cur);
                    }
                }
                c[i][j]=mn;
            }
        }
        vector<vector<int>> dp(k+1,vector<int>(n+1,1e9));
        dp[0][0]=0;
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                for(int p=j-1;p<i;p++){
                    dp[j][i]=min(dp[j][i],dp[j-1][p]+c[p][i-1]);
                }
            }
        }
        return dp[k][n];
    }
};
