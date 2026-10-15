class Solution{
public:
    string getHint(string secret,string guess){
        int bulls=0,cows=0;
        int count[10]={0};
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                if(count[secret[i]-'0']<0)cows++;
                count[secret[i]-'0']++;
                if(count[guess[i]-'0']>0)cows++;
                count[guess[i]-'0']--;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};