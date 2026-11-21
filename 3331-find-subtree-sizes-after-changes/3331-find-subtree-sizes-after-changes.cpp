class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> g(n);
        for(int i=1;i<n;i++){
            g[parent[i]].push_back(i);
        }
        vector<int> np=parent;
        vector<int> last(26,-1);
        auto dfs1=[&](auto& self,int u)->void{
            int c=s[u]-'a';
            int prev=last[c];
            if(u!=0&&prev!=-1){
                np[u]=prev;
            }
            last[c]=u;
            for(int v:g[u]){
                self(self,v);
            }
            last[c]=prev;
        };
        dfs1(dfs1,0);
        vector<vector<int>> ng(n);
        for(int i=1;i<n;i++){
            ng[np[i]].push_back(i);
        }
        vector<int> ans(n,1);
        auto dfs2=[&](auto& self,int u)->void{
            for(int v:ng[u]){
                self(self,v);
                ans[u]+=ans[v];
            }
        };
        dfs2(dfs2,0);
        return ans;
    }
};