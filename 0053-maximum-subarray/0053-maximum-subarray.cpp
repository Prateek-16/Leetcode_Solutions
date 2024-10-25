class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int curr = nums[0];
        for(int i = 1;i<nums.size();i++){
            curr = max(curr + nums[i] , nums[i]);
            maxi = max(curr , maxi);
            if(curr < 0){
                curr = 0;
            }
        }
        return maxi;
        
    }
};