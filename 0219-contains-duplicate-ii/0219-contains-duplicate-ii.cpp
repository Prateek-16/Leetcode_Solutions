class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i < n ;i++){
            int curr = nums[i];
            if(mp.count(curr) && abs(mp[curr] - i) <= k){
                cout<<mp[curr]<<" "<<i<<endl;
                return true;
            }
            mp[curr] = i;
        }
        return false;
    }
};