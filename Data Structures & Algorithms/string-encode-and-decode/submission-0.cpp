class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const string& s : strs) {
        res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
        string lenStr;
        while (s[i] != '#') {
            lenStr += s[i];
            i++;
        }
        int len = stoi(lenStr);
        i++; // bỏ qua '#'
        res.push_back(s.substr(i, len));
        i += len;
        }
        return res;
    }
};
