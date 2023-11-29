class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (auto num: nums) {
            int div = 0;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    if (div != 0) {
                        div = 0;
                        break;
                    }
                    div = i;
                }
            }
            if (div != 0 && num / div != div) ans += (1 + div + num / div + num);
        }
        return ans;
    }
};