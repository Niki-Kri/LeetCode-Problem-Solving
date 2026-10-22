class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==0) {
                idx=i;
                break;
            }
        }
        auto isValid=[&](int step)->bool {
            for(int i=1; i<n; i++) {
                int prev=(idx+(i-1)*step+n)%n;
                int curr=(idx+i*step+n)%n;
                if(nums[prev]>nums[curr]) {
                    return false;
                }
            }
            return true;
        };
        int ans=INT_MAX;
        if(isValid(1)) {
            ans=min(ans, idx);
            ans=min(ans, n-idx+2);
        }
        if(isValid(-1)) {
            ans=min(ans, idx+2);
            ans=min(ans, n-idx);
        }
        return ans==INT_MAX?-1:ans;
    }
};