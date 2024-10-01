class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
    
        while (low < high) {
            int mid = low + (high - low) / 2;
        
            if (nums[mid] < target) {
                low = mid + 1; // Move to the right half
            } else {
                high = mid; // Move to the left half or stay at mid
            }
        }
        return high;
    }
};