class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto w: words) {
            int start = 0, end = w.size() - 1;
            while (start < end) {
                if (w[start] != w[end]) break;
                else {
                    start++;
                    end--;
                }
            }
            if (start >= end) return w;
        }
        return "";
    }
};