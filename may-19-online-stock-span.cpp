// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
    vector<int> history;
    int icurrent;
    int currentmax;
    int icurrentmax;
public:
    StockSpanner() {
        icurrent = currentmax = icurrentmax = 0;
        history.push_back(0);
    }

    int next(int price) {
        ++icurrent;
        history.push_back(price);
        if (price >= currentmax)
        {
            currentmax = price;
            icurrentmax = icurrent;
            return icurrent;
        }
        for (int i = icurrent - 1; i >= icurrentmax; --i)
            if (history[i] > price) return icurrent - i;
        return 0;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */