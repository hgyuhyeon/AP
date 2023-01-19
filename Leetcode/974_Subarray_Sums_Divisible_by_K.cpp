class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0);
        int sum = 0, ans = 0;
        cnt[0]++;

        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i] % k + k) % k;
            // 기존 sum + 해당 위치 % k 해서 나머지 더해도 k로 나뉘어지는지
            // + k 는 오버플로우 방지용
            ans += cnt[sum];
            cnt[sum]++;
        }

        return ans;
    }
};