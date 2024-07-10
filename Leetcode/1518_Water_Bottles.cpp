class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem = 0, ans = 0;
        while (numBottles) {
            ans += numBottles;
            numBottles += rem;
            rem = numBottles % numExchange;
            numBottles /= numExchange;
        }
        return ans;
    }
};
