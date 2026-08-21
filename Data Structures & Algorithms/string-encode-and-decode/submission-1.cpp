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
        while(i < s.size()){
            string lenSt;
            while(s[i] != '#'){
                lenSt += s[i];
                i++;
            }
            int len = stoi(lenSt);
            i++;
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};
