class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);
        set<int> avail;
        for(int i=0;i<k;i++) avail.insert(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        int n=arrival.size();
        for(int i=0;i<n;i++){
            long long t=arrival[i];
            while(!busy.empty()&&busy.top().first<=t){
                avail.insert(busy.top().second);
                busy.pop();
            }
            if(avail.empty()) continue;
            auto it=avail.lower_bound(i%k);
            if(it==avail.end()) it=avail.begin();
            int s=*it;
            avail.erase(it);
            busy.push({t+load[i], s});
            cnt[s]++;
        }
        int mx=0;
        for(int x:cnt){
            mx=max(mx, x);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(cnt[i]==mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};