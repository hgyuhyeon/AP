class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string, int> v;
        for (auto d: deadends) v[d]++;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while (!q.empty()) {
            string num = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (v[num] > 0) continue;
            else if (num == target) return cnt;
            else {
                v[num]++;
                for (int i = 0; i < 4; i++) {
                    string t = num;
                    t[i] = (num[i]-'0'+9)%10+'0';
                    q.push({t, cnt+1});
                    t[i] = (num[i]-'0'+11)%10+'0';
                    q.push({t, cnt+1});
                }
            }
        }
        return -1;
    }
};