class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> bs(10, 0);
        vector<string> ans;
        for (int i = 9; turnedOn > 0; turnedOn--, i--) bs[i] = 1;
        do {
            int h = 0, m = 0;
            for (int i = 0; i < 4; i++) h = (h << 1) + bs[i];
            for (int i = 4; i < 10; i++) m = (m << 1) + bs[i];
            if (h < 12 && m < 60) ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
        } while (next_permutation(bs.begin(), bs.end()));
        return ans;
    }
};
