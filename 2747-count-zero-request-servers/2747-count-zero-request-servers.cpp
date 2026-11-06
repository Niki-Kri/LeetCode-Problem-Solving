class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=queries.size();
        vector<pair<int,int>> q(m);
        for(int i=0;i<m;i++) {
            q[i]={queries[i],i};
        }
        sort(q.begin(),q.end());
        sort(logs.begin(),logs.end(),[](const vector<int>& a,const vector<int>& b) {
            return a[1]<b[1];
        });
        vector<int> ans(m);
        vector<int> cnt(n+1,0);
        int active=0;
        int l=0,r=0;
        int size=logs.size();
        for(int i=0;i<m;i++) {
            int end=q[i].first;
            int start=q[i].first-x;
            int idx=q[i].second;
            while(r<size&&logs[r][1]<=end) {
                int id=logs[r][0];
                if(cnt[id]==0) {
                    active++;
                }
                cnt[id]++;
                r++;
            }
            while(l<size&&logs[l][1]<start) {
                int id=logs[l][0];
                cnt[id]--;
                if(cnt[id]==0) {
                    active--;
                }
                l++;
            }
            ans[idx]=n-active;
        }
        return ans;
    }
};