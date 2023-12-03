class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), cnt = 1, curr = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] != curr && cnt < 3) {
                curr = nums[i];
                cnt = 1;
            }
            else if (nums[i] == curr && cnt < 2) cnt++;
            else {
                for (int j = i; j < n - 1; j++) swap(nums[j], nums[j+1]);
                n--;
                if (curr != nums[i]) {
                    curr = nums[i];
                    cnt = 1;
                }
                else i--;
            }
        }
        return n;
    }
};