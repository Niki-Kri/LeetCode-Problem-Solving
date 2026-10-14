class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length()<10){
            return result;
        }
        unordered_map<string,int> countMap;
        for(int i=0;i<=s.length()-10;i++){
            string sub=s.substr(i,10);
            countMap[sub]++;
        }
        for(auto const& [sub,count]:countMap){
            if(count>1){
                result.push_back(sub);
            }
        }
        return result;
    }
};