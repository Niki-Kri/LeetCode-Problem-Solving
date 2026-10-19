class Solution {
public:
    string reverseVowels(string s) {
        string vowels="aeiouAEIOU";
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(vowels.find(s[i])==string::npos){
                i++;
            }
            if(vowels.find(s[j])==string::npos){
                j--;
            }
            else if(vowels.find(s[i])!=string::npos && vowels.find(s[j])!=string::npos) {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};