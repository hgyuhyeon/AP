class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), b = 0, c = 0;
        map<char, int> m;
        for (auto c: secret) m[c]++;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                b++;
                if (m[guess[i]] <= 0) c--;
            }
            else if (m[guess[i]] > 0) c++;
            m[guess[i]]--;
        }
        return to_string(b) + "A" + to_string(c) + "B";
    }
};