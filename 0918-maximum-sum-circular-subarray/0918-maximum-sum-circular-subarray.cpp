class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        
        int currSum1 = nums[0];
        int currSum2 = nums[0];
        
        int totalSum = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            totalSum += nums[i];
            
            currSum1 = max(currSum1 + nums[i] , nums[i]);
            currSum2 = min(currSum2 + nums[i] , nums[i]);
            
            maxSum = max(currSum1 , maxSum);
            
            minSum = min(minSum , currSum2);
        }
        
        if (maxSum < 0) {
            // If all numbers are negative, return the maximum subarray sum
            return maxSum;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};