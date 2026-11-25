class Solution {
public:
    bool check(vector<int>& nums,int len){
        unordered_map<unsigned long long,int> mp;
        unsigned long long base=100003;
        unsigned long long hash=0,power=1;
        int n=nums.size();
        for(int i=0;i<len;i++){
            hash=hash*base+nums[i];
            if(i<len-1)
                power*=base;
        }
        mp[hash]++;
        for(int i=len;i<n;i++){
            hash=(hash-nums[i-len]*power)*base+nums[i];
            mp[hash]++;
        }
        for(auto &p:mp){
            if(p.second==1)
                return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums){
        int low=1,high=nums.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,mid))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};
