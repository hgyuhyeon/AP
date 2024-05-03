class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0, tmp1 = 0, tmp2 = 0;
        while (i < v1.size() || j < v2.size()) {
            while (i < v1.size() && v1[i] != '.') tmp1 = tmp1*10 + (v1[i++]-'0');
            while (j < v2.size() && v2[j] != '.') tmp2 = tmp2*10 + (v2[j++]-'0');
            if (tmp1 > tmp2) return 1;
            else if (tmp1 < tmp2) return -1;
            tmp1 = 0; i++;
            tmp2 = 0; j++;
        }
        return 0;
    }
};