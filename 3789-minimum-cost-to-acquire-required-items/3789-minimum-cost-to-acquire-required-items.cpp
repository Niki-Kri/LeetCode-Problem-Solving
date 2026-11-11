class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a=cost1;
        long long b=cost2;
        long long c=costBoth;
        long long x=need1;
        long long y=need2;
        if(c>=a+b){
            return x*a+y*b;
        }
        long long m=min(x,y);
        long long ans=m*c;
        if(x>y){
            ans+=(x-y)*min(a,c);
        }else if(y>x){
            ans+=(y-x)*min(b,c);
        }
        return ans;
    }
};