class Solution {
public:
    int sortableIntegers(vector<int>&nums){
        int n=nums.size();
        int totalSum=0;
        for(int k=1;k<=n;++k){
            if(n%k!=0)continue;
            bool ok=true;
            int prevMax=-1e9;
            for(int i=0;i<n;i+=k){
                int drops=0;
                int mn=1e9,mx=-1e9;
                for(int j=0;j<k;++j){
                    int curr=nums[i+j];
                    mn=min(mn,curr);
                    mx=max(mx,curr);
                    int next=nums[i+(j+1)%k];
                    if(curr>next)drops++;
                }
                if(drops>1){
                    ok=false;
                    break;
                }
                if(mn<prevMax){
                    ok=false;
                    break;
                }
                prevMax=mx;
            }
            if(ok)totalSum+=k;
        }
        return totalSum;
    }
};