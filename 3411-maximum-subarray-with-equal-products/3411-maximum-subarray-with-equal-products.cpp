#define ll long long

class Solution {
public:
    ll gcd(ll a,ll b){
        while(b!=0){
            ll t=a%b;
            a=b;
            b=t;
        }
        return a;
    }

    ll lcm(ll a,ll b){
        return (a/gcd(a,b))*b;
    }

    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            ll p=1;
            ll g=0;
            ll l=1;
            for(int j=i;j<n;j++){
                ll x=nums[j];
                if(p>4000000000LL/x) break;
                p=p*x;
                if(g==0) g=x;
                else g=gcd(g,x);
                l=lcm(l,x);
                if(p==l*g){
                    int len=j-i+1;
                    if(len>ans) ans=len;
                }
            }
        }
        return ans;
    }
};