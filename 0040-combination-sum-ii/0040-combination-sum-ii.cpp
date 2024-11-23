class Solution {
public:
    void solve(vector<int>& candidates , int target , vector<int>&curr , vector<vector<int>>& ans , int index){
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        
        for(int i = index; i< candidates.size();i++){
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates,target - candidates[i],curr,ans,i + 1);
            curr.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        int index = 0;
        sort(candidates.begin(),candidates.end());
        solve(candidates , target , curr , ans , index);
        return ans;
        
    }
};