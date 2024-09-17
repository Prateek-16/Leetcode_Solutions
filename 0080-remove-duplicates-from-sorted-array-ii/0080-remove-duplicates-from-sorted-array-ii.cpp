class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;

        int i = 0;
        int j = 0;

        while(j < nums.size()){
            if(mp[nums[j]] < 2 ){
                mp[nums[j]]++;
                swap(nums[i] , nums[j]);
                i++;
            }
            j++;
        }
        return i;
    }
};