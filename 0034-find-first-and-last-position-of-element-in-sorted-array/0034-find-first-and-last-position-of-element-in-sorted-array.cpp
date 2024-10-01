class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int startingPos = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int endingPos = lower_bound(nums.begin(),nums.end(),target + 1) - nums.begin() - 1;
        
        if(startingPos < nums.size() && nums[startingPos] == target){
            return {startingPos,endingPos};
        }
        return {-1,-1};
        
    }
};