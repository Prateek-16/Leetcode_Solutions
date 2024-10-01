class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<32;i++){
            int sum = 0;
            for(const int num : nums){
                sum += (num >> i) & 1;
            }
            sum %= 3;   //After this step sum will either be 0 or 1.
                        //if its 1 it indicates that the single element has a set bit at i'th position
            if(sum) ans |= sum << i;
        }
        return ans;
        
        
    }
};