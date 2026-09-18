#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        if(str.length()>3||str.length()==0)return false;
        if(str[0]=='0'&&str.length()>1)return false;
        int num=0;
        for(int i=0;i<str.length();i++) {
            num=num*10+(str[i]-'0');
        }
        if(num>255)return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n=s.length();
        if(n<4||n>12)return res;
        for(int i=1;i<4;i++) {
            for(int j=1;j<4;j++) {
                for(int k=1;k<4;k++) {
                    int l=n-i-j-k;
                    if(l>0&&l<=3) {
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(i+j,k);
                        string d=s.substr(i+j+k,l);
                        if(isValid(a)&&isValid(b)&&isValid(c)&&isValid(d)) {
                            res.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        return res;
    }
};