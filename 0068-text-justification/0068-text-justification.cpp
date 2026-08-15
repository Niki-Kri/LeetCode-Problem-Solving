class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int mx) {
        vector<string> res;
        vector<string> cw;
        int len = 0;
        for (int i = 0; i < w.size(); i++) {
            string s = w[i];
            if (cw.size() == 0 || len + cw.size() + s.length() <= mx) {
                cw.push_back(s);
                len = len + s.length();
            } else {
                string line = "";
                int spc = mx - len;
                if (cw.size() == 1) {
                    line = line + cw[0];
                    for (int j = 0; j < spc; j++) {
                        line = line + " ";
                    }
                } else {
                    int bSpc = spc / (cw.size() - 1);
                    int eSpc = spc % (cw.size() - 1);
                    for (int k = 0; k < cw.size(); k++) {
                        line = line + cw[k];
                        if (k < cw.size() - 1) {
                            for (int j = 0; j < bSpc; j++) {
                                line = line + " ";
                            }
                            if (eSpc > 0) {
                                line = line + " ";
                                eSpc = eSpc - 1;
                            }
                        }
                    }
                }
                res.push_back(line);
                cw.clear();
                cw.push_back(s);
                len = s.length();
            }
        }
        string last = "";
        for (int k = 0; k < cw.size(); k++) {
            last = last + cw[k];
            if (k < cw.size() - 1) {
                last = last + " ";
            }
        }
        int tSpc = mx - last.length();
        for (int j = 0; j < tSpc; j++) {
            last = last + " ";
        }
        res.push_back(last);
        return res;
    }
};