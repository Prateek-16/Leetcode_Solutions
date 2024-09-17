class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>st;

        int i = 0;
        int j = 0;

        while(j < nums.size()){
            if(st.find(nums[j]) == st.end() ){
                st.insert(nums[j]);
                swap(nums[i] , nums[j]);
                i++;
            }
            j++;
        }
        return i;
        
    }
};