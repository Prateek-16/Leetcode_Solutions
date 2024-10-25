class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>n1(nums1.begin(),nums1.end());
        unordered_set<int>n2(nums2.begin(),nums2.end());
        vector<int>ans;
        for(auto it : n1){
            if( n2.find(it) != n2.end()){
                ans.push_back(it);
            }
        }
        return ans;
        
    }
};