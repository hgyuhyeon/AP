class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        static map<int, int> fq;
        fq.clear();
        for (int i: nums) fq[i]++;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            if (fq[a] == fq[b]) return a > b;
            return fq[a] < fq[b];
        });
        return nums;
    }
};
