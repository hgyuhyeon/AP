class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0, in = word1.size(), jn = word2.size();
        while (i < in && j < jn) {
            if (word1[i] == word2[j]) {
                int i2 = i, j2 = j;
                while (i2 < in && j2 < jn) {
                    if (word1[i2] > word2[j2]) {
                        ans += word1[i++];
                        break;
                    }
                    else if (word1[i2] < word2[j2]) {
                        ans += word2[j++];
                        break;
                    }
                    i2++;
                    j2++;
                }
                if (i2 >= in || j2 >= jn) ans += (i2 >= in) ? word2[j++] : word1[i++];
            }
            else if (word1[i] > word2[j]) ans += word1[i++];
            else ans += word2[j++];
        }
        if (i >= in || j >= jn) ans += (i >= in) ? word2.substr(j) : word1.substr(i);
        return ans;
    }
};