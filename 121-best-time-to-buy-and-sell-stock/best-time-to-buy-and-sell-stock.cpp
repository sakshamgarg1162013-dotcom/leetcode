class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int mini = prices[0];
        int maxprofit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }

            int profit = prices[i] - mini;
            if(profit > maxprofit){
                maxprofit = profit;
            }
        }
        return maxprofit;
    }
};