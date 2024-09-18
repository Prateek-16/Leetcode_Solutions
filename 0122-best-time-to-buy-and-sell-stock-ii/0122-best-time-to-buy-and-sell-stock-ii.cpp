class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Simple Greedy Solution
        //Buy whenever price of current day is lower
        //Sell whenever price of current day is higher
        //Add all profit in ans
        
        int profit = 0;
        int buy = INT_MAX;
        int sell = 0;
        
        for(int i = 0;i < prices.size() ; i++){
            buy = min(buy,prices[i]);
            if(prices[i] > buy){
                profit += prices[i] - buy;
                buy = prices[i];
            }
            
        }
        return profit;
        
    }
};