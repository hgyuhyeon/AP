class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        int n = hand.size(), prev, cnt;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++) {
            if (hand[i] == -1) continue;
            prev = hand[i];
            cnt = 1;
            hand[i] = -1;
            for (int j = i + 1; j < n && cnt < groupSize; j++) {
                if (hand[j] == -1) continue;
                else if (hand[j] > prev + 1) return false;
                else if (hand[j] == prev + 1) {
                    prev = hand[j];
                    hand[j] = -1;
                    cnt++;
                }
            }
            if (cnt < groupSize) return false;
        }
        return true;
    }
};