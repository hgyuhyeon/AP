class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flip0 = 0, flip1 = 0;

        for (auto c: s) {
            if (c == '1') flip1++;
            else flip0++;
            flip0 = min(flip0, flip1);
        }

        return flip0;
    }
};