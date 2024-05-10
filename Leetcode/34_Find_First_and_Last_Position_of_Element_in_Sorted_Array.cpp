class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        int lo = 0, hi = nums.size()-1, mid, n = nums.size();
        vector<int> ans;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            if (nums[mid] == target) {
                int lo2 = 0, hi2 = mid;
                while (lo2 <= hi2) {
                    int mid2 = (lo2+hi2)/2;
                    if (nums[mid2] != target) lo2 = mid2+1;
                    else if (mid2 == 0 || nums[mid2-1] < nums[mid2]) {
                        ans.push_back(mid2);
                        break;
                    }
                    else hi2 = mid2-1;
                }
                lo2 = mid, hi2 = n-1;
                while (lo2 <= hi2) {
                    int mid2 = (lo2+hi2)/2;
                    if (nums[mid2] != target) hi2 = mid2-1;
                    else if (mid2 == n-1 || nums[mid2+1] > nums[mid2]) {
                        ans.push_back(mid2);
                        break;
                    }
                    else lo2 = mid2+1;
                }
                break;
            }
            else if (nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return ans.size() ? ans : vector<int>{-1, -1};
    }
};