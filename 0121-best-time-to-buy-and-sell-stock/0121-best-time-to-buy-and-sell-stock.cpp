class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = 0;
        int i = 0;
        while (i < prices.size()) {
            buy = min(buy,prices[i]);
            sell = max(sell, prices[i] - buy);
            i++;
        }
        return sell;
    }
};