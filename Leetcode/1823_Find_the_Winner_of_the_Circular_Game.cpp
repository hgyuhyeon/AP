class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);
        int i = 1;
        while (q.size() > 1) {
            if (i++ < k) q.push(q.front());
            else i = 1;
            q.pop();
        }
        return q.front();
    }
};