class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        int n=s.size();
        int m=t.size();
        vector<int> res(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeQ;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyQ;
        for(int i=0;i<n;i++) {
            freeQ.push({s[i], i});
        }
        long long time=0;
        for(int j=0; j<m; j++) {
            time=max(time, (long long)j);
            if(freeQ.empty()) {
                time=busyQ.top().first;
            }
            while(!busyQ.empty() && busyQ.top().first<=time) {
                int idx=busyQ.top().second;
                busyQ.pop();
                freeQ.push({s[idx],idx});
            }
            auto [w, idx]=freeQ.top();
            freeQ.pop();
            res[j]=idx;
            busyQ.push({time+t[j],idx});
        }
        return res;
    }
};