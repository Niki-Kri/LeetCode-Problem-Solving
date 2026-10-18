class Solution{
    long long mod=1e9+7;

    long long power(long long base,long long exp){
        long long res=1;
        base%=mod;
        while(exp>0){
            if(exp%2==1)res=(res*base)%mod;
            base=(base*base)%mod;
            exp/=2;
        }
        return res;
    }

    long long modInverse(long long n){
        return power(n,mod-2);
    }

    long long nCr(int n,int r){
        if(r==0||r==n)return 1;
        long long num=1,den=1;
        for(int i=0;i<r;i++){
            num=(num*(n-i))%mod;
            den=(den*(i+1))%mod;
        }
        return (num*modInverse(den))%mod;
    }

    long long solve(vector<int>&nums){
        int n=nums.size();
        if(n<=2)return 1;
        vector<int>left,right;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[0])left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long left_ways=solve(left);
        long long right_ways=solve(right);
        long long ways=(nCr(n-1,left.size())*left_ways)%mod;
        ways=(ways*right_ways)%mod;
        return ways;
    }

public:
    int numOfWays(vector<int>&nums){
        return (solve(nums)-1+mod)%mod;
    }
};