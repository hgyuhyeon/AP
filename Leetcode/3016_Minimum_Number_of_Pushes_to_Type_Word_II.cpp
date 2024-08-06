class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);
        for (auto c: word) v[c-'a']++;
        sort(v.begin(), v.end(), greater<>());
        int push = 1, cnt = 0, ans = 0;
        for (int i = 0; i < 26 && v[i] > 0; i++) {
            ans += (v[i] * push);
            cnt++;
            if (cnt == 8) {
                push++;
                cnt = 0;
            }
        }
        return ans;
    }
};
