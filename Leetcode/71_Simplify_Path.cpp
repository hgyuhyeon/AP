class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        deque<string> d;
        d.push_back("/");
        int n = path.size(), i = -1;
        string tmp = "";
        while (++i < n) {
            if (path[i] == '/') {
                if (d.back() != "/") d.push_back("/");
                else if (tmp.size() > 0) {
                    if (tmp == "..") {
                        if (d.size() > 1) d.pop_back();
                        while (d.back() != "/") d.pop_back();
                    }
                    else if (tmp != ".") {
                        d.push_back(tmp);
                        d.push_back("/");
                    }
                    tmp = ""; 
                }
            }
            else tmp += path[i];
        }

        if (d.size() > 1) d.pop_back();
        string ans = "";
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
        }
        return ans;
    }
};