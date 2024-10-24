class Solution {
public:
    bool check(string& word , vector<string>&wordDict){
        for(string it : wordDict){
            if(word == it){
                return true;
            }
        }
        return false;
    }
    bool solve(string& s, vector<string>&wordDict, vector<int>&dp,int index){
        if(index >= s.size()){
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        string word = "";
        bool flag = false;
        for(int i = index ; i < s.size() ; i++){
            word += s[i];
            if(check(word, wordDict)){
                flag = flag || solve(s , wordDict , dp, i + 1);
            }
        }
        return dp[index] = flag;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size() + 1, -1);
        return solve(s,wordDict,dp,0);
        
    }
};