class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n=m.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0;i<n;i++) {
            pq.push({m[i][0],{i,0}});
        }
        int res=0;
        for(int c=0;c<k;c++) {
            auto cur=pq.top();
            pq.pop();
            res=cur.first;
            int r=cur.second.first;
            int col=cur.second.second;
            if(col+1<n) {
                pq.push({m[r][col+1], {r,col+1}});
            }
        }
        return res;
    }
};