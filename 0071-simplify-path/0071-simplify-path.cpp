class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stringstream ss(path);
        string dir = "";
        vector<string> st;
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                continue;
            }
            if (dir == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(dir);
            }
        }
        for (string s : st) {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};