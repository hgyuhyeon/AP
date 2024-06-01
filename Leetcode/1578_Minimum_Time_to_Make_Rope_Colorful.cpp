class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for (int i = colors.size()-2, back = i+1; i >= 0; i--) {
            if (colors[i] == colors[back]) {
                if (neededTime[i] >= neededTime[back]) {
                    ans += neededTime[back];
                    back = i;
                }
                else ans += neededTime[i];
            }
            else back = i;
        }
        return ans;
    }
};