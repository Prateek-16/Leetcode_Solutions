class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            int value = target - nums[i];
            if(mp.find(value) != mp.end()){
                return {i,mp[value]};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {};
        
    }
};