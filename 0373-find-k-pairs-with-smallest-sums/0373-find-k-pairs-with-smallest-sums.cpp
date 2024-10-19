class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        
        for(int i = 0;i<nums1.size();i++){
            int sum = nums2[0] + nums1[i];
            pq.push({sum,0});
        }
        
        while(k-- && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int index = top.second;
            
            int num1 = sum - nums2[index];
            int num2 = nums2[index];
            
            ans.push_back({num1,num2});
            
            if(index < nums2.size() - 1 ){
                pq.push({num1 + nums2[index + 1] , index + 1});
            }   
        }
        return ans;
    }
};