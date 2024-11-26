class Solution {
public:
    void solve(int n , int open , int close , vector<string>& ans , string curr){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            solve(n , open + 1 , close , ans , curr + "(");
        }
        if(close < open){
            solve(n , open , close + 1 , ans , curr + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        
        vector<string>ans;
        string curr = "";
        
        solve(n, open , close , ans , curr);
        return ans;
    }
};