class Solution{
public:
    bool canFinish(int numCourses,vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses,0);
        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]);
            ind[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            for(int v:adj[u]){
                ind[v]--;
                if(ind[v]==0) q.push(v);
            }
        }
        return cnt==numCourses;
    }
};