class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size(), lo = 0, hi = n-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (mid == 0 || mid == n-1 || (arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])) return mid;
            else if (arr[mid-1] > arr[mid]) hi = mid;
            else lo = mid;
        }
        return arr[lo];
    }
};