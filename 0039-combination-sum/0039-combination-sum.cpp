class Solution {
public:
    void solve(vector<int>& candidates, int target , vector<vector<int>>& ans , vector<int>& curr , int index){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = index ; i < candidates.size();i++){
            if(candidates[i] <= target){
                curr.push_back(candidates[i]);
                solve(candidates , target - candidates[i] , ans , curr , i);
                curr.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int index = 0;
        solve(candidates , target , ans , curr , index);
        return ans;
    }
};