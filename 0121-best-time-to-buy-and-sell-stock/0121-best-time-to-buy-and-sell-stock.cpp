class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
           return 0;

        int minprice = prices[0];
        int maxprofit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profittoday = prices[i] - minprice;
            maxprofit = max(maxprofit, profittoday);

            if (prices[i] < minprice) {
                minprice = prices[i];
            }
        }
        return maxprofit;
    }
};
