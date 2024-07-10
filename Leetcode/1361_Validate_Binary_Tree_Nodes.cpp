class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            vector<bool> v(n, false);
            v[i] = true;
            int cnt = 1;
            while (!q.empty()) {
                int cur = q.front();
                if (leftChild[cur] != -1) {
                    if (!v[leftChild[cur]]) {
                        q.push(leftChild[cur]);
                        v[leftChild[cur]] = true;
                        cnt++;
                    }
                    else return false;
                }
                if (rightChild[cur] != -1) {
                    if (!v[rightChild[cur]]) {
                        q.push(rightChild[cur]);
                        v[rightChild[cur]] = true;
                        cnt++;
                    }
                    else return false;
                }
                q.pop();
            }
            if (cnt == n) return true;
        }
        return false;
    }
};
