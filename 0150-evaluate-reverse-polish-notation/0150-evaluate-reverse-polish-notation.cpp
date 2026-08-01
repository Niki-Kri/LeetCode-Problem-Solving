class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size() / 2 + 1);
        for (const string& token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                int b = st.back(); 
                st.pop_back();
                int a = st.back(); 
                st.pop_back();
                switch(token[0]) {
                    case '+': st.push_back(a + b); break;
                    case '-': st.push_back(a - b); break;
                    case '*': st.push_back(a * b); break;
                    case '/': st.push_back(a / b); break;
                }
            } else {
                st.push_back(stoi(token));
            }
        }
        return st.back();
    }
};