class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> lastIdx;
        int left=0;
        int mxLen=0;
        for(int right=0;right<n;right++){
            if(lastIdx.count(s[right]) && lastIdx[s[right]]>=left){
                left=lastIdx[s[right]]+1;
            }
            lastIdx[s[right]]=right;
            mxLen=max(mxLen,right-left+1);
        }
        return mxLen;
    }
};