class Solution {
    int Pivot_element(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <= e) {
            if (s == e) {
                return s;
            }
            if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            } else if (nums[0] > nums[mid]) {
                // we are in B part
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }
    int binarysearch(vector<int>& nums, int target, int s, int e) {
        int mid = s + (e - s) / 2;
        while (s <= e) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int ans = -1;

        int pivot_index = Pivot_element(nums);
        if (target >= nums[0]) {
            ans = binarysearch(nums, target, 0, pivot_index);
        } else {
            ans = binarysearch(nums, target, pivot_index + 1, n);
        }
        return ans;
    }
};