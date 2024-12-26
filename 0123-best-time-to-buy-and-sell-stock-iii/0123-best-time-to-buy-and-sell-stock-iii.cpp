class Solution {
public:
    int solvewithMem(vector<int>& prices, int index, bool buy,
                     vector<vector<vector<int>>>& dp, int limit) {
        if (index >= prices.size() || limit <= 0) {
            return 0;
        }
        if (dp[index][buy][limit] != -1) {
            return dp[index][buy][limit];
        }
        int profit = 0;
        if (buy) {
            int buyProfit =
                solvewithMem(prices, index + 1, 0, dp, limit) - prices[index];
            int skipProfit = solvewithMem(prices, index + 1, 1, dp, limit);
            profit = max(buyProfit, skipProfit);
        } else {
            int sellProfit = prices[index] +
                             solvewithMem(prices, index + 1, 1, dp, limit - 1);
            int SkipProfit = solvewithMem(prices, index + 1, 0, dp, limit);
            profit = max(sellProfit, SkipProfit);
        }
        return dp[index][buy][limit] = profit;
    }

    int solvewithTab(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int limit=1;limit<3;limit++ ) {
                    int profit = 0;
                    if (buy) {
                        int buyProfit = dp[index + 1][0][limit] - prices[index];
                        int skipProfit =
                            dp[index+1][1][limit];
                        profit = max(buyProfit, skipProfit);
                    } else {
                        int sellProfit =
                            prices[index] +
                            dp[index+1][1][limit-1];
                        int SkipProfit =
                            dp[index+1][0][limit];
                        profit = max(sellProfit, SkipProfit);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(
        //     prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // return solvewithMem(prices, 0, 1, dp, 2);
        return solvewithTab(prices);
    }
};