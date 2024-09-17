class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Reverse Solution
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};