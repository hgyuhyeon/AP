class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int freq = 0, val = 0;
        for (auto i: nums) freq = max(freq, ++m[i]);
        for (auto i: m) if (freq == i.second) val++;
        return freq * val;
    }
};