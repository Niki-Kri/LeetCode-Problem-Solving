class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int total=10,unique=9,avail=9;
        for(int i=2;i<=n;i++){
            unique*=avail;
            total+=unique;
            avail--;
        }
        return total;
    }
};