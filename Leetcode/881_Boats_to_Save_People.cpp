class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1, w, cnt, ans = 0;
        if (i == j) return 1;
        while (i <= j) {
            w = 0;
            cnt = 0;
            while (w + people[j] <= limit && cnt < 2 && i < j) {
                w += people[j--];
                cnt++;
            }
            while (w + people[i] <= limit && cnt < 2 && i <= j) {
                w += people[i++];
                cnt++;
            }
            ans++;
        }
        return ans;
    }
};