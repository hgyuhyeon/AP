class Solution {
public:
    string simplifyPath(string path) {
        deque<string> d;
        string tmp = "";
        d.push_back("/");
        for (auto c: path) {
            if (c == '/') {
                if (tmp == "" || tmp == ".") {
                    tmp = "";
                    continue;
                }
                if (tmp == "..") {
                    if (d.size() > 1) d.pop_back();
                    if (d.size() > 1) d.pop_back();
                    tmp = "";
                    continue;
                }
                else {
                    d.push_back(tmp);
                    tmp = "";
                }
                d.push_back("/");
            }
            else tmp += c;
        }

        if (d.size() > 1 && d.back() == "/") d.pop_back();

        if (tmp == "..") {
            if (d.size() > 1) d.pop_back();
            if (d.size() > 1) d.pop_back();
        }
        else if (tmp == "" || tmp == ".") {}
        else {
            if (d.back() == "/") d.push_back(tmp);
            else d.push_back("/" + tmp);
        }

        string ans = "";
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
        }
        
        if (ans == "") return "/";
        return ans;
    }
};