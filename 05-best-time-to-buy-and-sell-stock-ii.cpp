// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_length = 1, current_sum = 0;
        if (prices.size() == 0) return 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i])
            {
                current_length++;
                if (i == prices.size() - 2) current_sum += prices[i + 1] - prices[i - current_length + 2];
            }
            else if (current_length > 1)
            {
                current_sum += prices[i] - prices[i - current_length + 1];
                current_length = 1;
            }
        }
        return current_sum;
    }
};