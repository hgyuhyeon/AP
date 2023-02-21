class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        else if (nums[0] != nums[1]) return nums[0];
        else if (nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
        int start = 0, end = nums.size() - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            cout << start << " " << mid << " " << end << endl;
            if (nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 1) start = mid + 1;
                else end = mid - 1;
            } 
            else if (nums[mid] == nums[mid + 1]) {
                if ((nums.size() - 1 - mid) % 2 == 0) start = mid + 1;
                else end = mid - 1;
            }
            else return nums[mid];
        }

        return nums[mid];
    }
};