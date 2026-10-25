class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int n=t.size();
        if(n==0)return 0;
        int res=0;
        for(int i=0;i<n-1;i++){
            int g=t[i+1]-t[i];
            if(g<d)res+=g;
            else res+=d;
        }
        res+=d;
        return res;
    }
};
