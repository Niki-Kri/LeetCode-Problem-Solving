class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        long long o=0,e=1,s=0,ans=0,m=1e9+7;
        for(int x:a){
            s+=x;
            if(s%2!=0){
                ans=(ans+e)%m;
                o++;
            }else{
                ans=(ans+o)%m;
                e++;
            }
        }
        return ans;
    }
};