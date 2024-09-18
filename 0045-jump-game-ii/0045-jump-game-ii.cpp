class Solution {
public:
    int jump(vector<int>& nums) {
        int reachable = nums[0];
        int i = 0;
        int max_index = 0;
        int count = 0;
        
        while(i < nums.size() - 1){
            if(reachable >= nums.size() -1 ){
                return count + 1;
            }
            int size = reachable;
            for(int it = i + 1; it <= size ;it++){
                if(it < nums.size() && nums[it] + it > reachable){
                    reachable = nums[it] + it;
                    max_index = it;
                    
                }
            }
            count++;
            i = max_index;
        }
        return count;
    }
};