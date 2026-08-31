class Solution{
public:
    int minMutation(string startGene,string endGene,vector<string>& bank){
        unordered_set<string> dict(bank.begin(),bank.end());
        if(!dict.count(endGene)) return -1;
        queue<string> q;
        q.push(startGene);
        int ans=0;
        char mut[]={'A','C','G','T'};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string cur=q.front();
                q.pop();
                if(cur==endGene) return ans;
                for(int i=0;i<8;i++){
                    char orig=cur[i];
                    for(int j=0;j<4;j++){
                        cur[i]=mut[j];
                        if(dict.count(cur)){
                            dict.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[i]=orig;
                }
            }
            ans++;
        }
        return -1;
    }
};