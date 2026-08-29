class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long result = 0;
        long long number = 0;
        int sign = 1;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                number = 10 * number + (c - '0');
            } else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            } else if (c == ')') {
                result += sign * number;
                number = 0;
                result *= st.top(); 
                st.pop();
                result += st.top(); 
                st.pop();
            }
        }
        result += sign * number;
        return result;
    }
};