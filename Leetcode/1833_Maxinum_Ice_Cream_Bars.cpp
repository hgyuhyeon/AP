class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (auto c: costs) {
            if (coins - c >= 0) {
                coins -= c;
                res++;
            }
            else break;
        }

        return res;
    }
};