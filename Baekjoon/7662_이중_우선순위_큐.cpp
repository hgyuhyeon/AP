#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    vector<string> ans(t);
    for (int tc = 0; tc < t; tc++) {
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        unordered_map<int, int> m;
        cin >> n;
        for (int nn = 0; nn < n; nn++) {
            char cmd;
            int val;
            cin >> cmd >> val;
            if (cmd == 'I') {
                pq1.push(val);
                pq2.push(val);
                m[val]++;
            }
            else {
                if (val == 1) {
                    while (!pq1.empty()) {
                        if (m[pq1.top()] > 0) {
                            m[pq1.top()]--;
                            pq1.pop();
                            break;
                        }
                        pq1.pop();
                    }
                }
                else {
                    while (!pq2.empty()) {
                        if (m[pq2.top()] > 0) {
                            m[pq2.top()]--;
                            pq2.pop();
                            break;
                        }
                        pq2.pop();
                    }
                }
            }
        }
        while (!pq1.empty()) {
            if (m[pq1.top()] > 0) break;
            pq1.pop();
        }
        while (!pq2.empty()) {
            if (m[pq2.top()] > 0) break;
            pq2.pop();
        }
        if (pq1.empty() && pq2.empty()) ans[tc] = "EMPTY";
        else ans[tc] = to_string(pq1.top()) + " " + to_string(pq2.top());
    }

    for (auto a: ans) cout << a << endl;
    
    return 0;
}