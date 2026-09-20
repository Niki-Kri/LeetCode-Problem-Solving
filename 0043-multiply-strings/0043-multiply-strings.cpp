class Solution{
public:
    string addStrings(string num1,string num2){
        string result="";
        int i=num1.length()-1;
        int j=num2.length()-1;
        int carry=0;
        while(i>=0||j>=0||carry>0){
            int sum=carry;
            if(i>=0){
                sum=sum+(num1[i]-'0');
                i--;
            }
            if(j>=0){
                sum=sum+(num2[j]-'0');
                j--;
            }
            result=to_string(sum%10)+result;
            carry=sum/10;
        }
        return result;
    }

    string multiply(string num1,string num2){
        if(num1=="0"||num2=="0"){
            return "0";
        }
        string finalAnswer="0";
        for(int i=num2.length()-1;i>=0;i--){
            int digit2=num2[i]-'0';
            string currentResult="";
            int carry=0;
            for(int j=num1.length()-1;j>=0;j--){
                int digit1=num1[j]-'0';
                int product=(digit1*digit2)+carry;
                currentResult=to_string(product%10)+currentResult;
                carry=product/10;
            }
            if(carry>0){
                currentResult=to_string(carry)+currentResult;
            }
            int numZeros=(num2.length()-1)-i;
            for(int z=0;z<numZeros;z++){
                currentResult=currentResult+"0";
            }
            finalAnswer=addStrings(finalAnswer,currentResult);
        }
        return finalAnswer;
    }
};