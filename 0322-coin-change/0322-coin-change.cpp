class Solution {
public:
    int solve(vector<int>& coins , int amount , vector<int>& dp){
        if(amount <= 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        int ans = INT_MAX;
        for(auto it : coins){
            if(it <= amount){
                int rec_Ans = solve(coins, amount - it , dp);
                if(rec_Ans != INT_MAX){
                    ans = 1 + rec_Ans;
                }
            }
            mini = min(mini , ans);
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int>dp(amount + 1 , -1);
        int ans = solve(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};