class Solution {
public:
    bool isHappy(int n) {
        map<int, int> m;
        do {
            int sum = 0;
            while (n > 0) {
                sum += ((n % 10) * (n % 10));
                n /= 10;
            }
            n = sum;
            if (m[n] > 0) return false;
            else m[n]++;
        } while(n != 1);
        return true;
    }
};