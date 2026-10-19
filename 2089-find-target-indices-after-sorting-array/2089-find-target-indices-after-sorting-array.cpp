class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector <int> ans;
        int count=0;
        for(int i=0;i<n;i++){
            if(count > 0 and nums[i]!=target){
                break;
            }
            else if(count=0 and nums[i]!= target){
                continue;
            }
            else if(nums[i]==target){
                count++;
                ans.push_back(i);
            }
        }
        return ans;  
    }
};