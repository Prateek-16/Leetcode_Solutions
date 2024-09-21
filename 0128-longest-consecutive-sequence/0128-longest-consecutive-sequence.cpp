class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans = 0;
        for(int it : nums){
            //it must be the starting point of a sequence
            if(st.contains(it - 1)){
                continue;
            }
            int length = 1;
            while(st.contains(++it)){
                ++length;
            }
            ans = max(length,ans);
        }
        return ans;
    }
};