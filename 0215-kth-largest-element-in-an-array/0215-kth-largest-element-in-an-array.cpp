class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>pq;
        //first K elements
        for(int i=0;i<n;i++){
            int element = nums[i];
            pq.push(element);
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        int ans = pq.top();
        return ans;
    }
};