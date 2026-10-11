class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num:nums){
            count[num]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& [num,freq]:count){
            buckets[freq].push_back(num);
        }
        vector<int> result;
        int n=buckets.size();
        for(int i=0;i<n;i++){
            int idx=n-1-i;
            for(int j=0;j<buckets[idx].size();j++){
                result.push_back(buckets[idx][j]);
                if(result.size()==k){
                    return result;
                }
            }
        }
        return result;
    }
};