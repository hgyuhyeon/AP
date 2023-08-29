class Solution {
public:
    int bestClosingTime(string customers) {
        int cnt = 0, maxCnt = 0, ans = -1, n = customers.size();
        for (int i = 0; i < n; i++) {
            cnt += (customers[i] == 'Y' ? 1 : -1);
            if (maxCnt < cnt) {
                maxCnt = cnt;
                ans = i;
            } 
        }
        return ans + 1;
    }
};