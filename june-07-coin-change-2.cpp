// https://leetcode.com/problems/coin-change-2/

// TLE:
//class Solution {
//    int** dp;
//    int recur(int amount, vector<int>& coins, int cur)
//    {
//        if (amount < 0) return 0;
//        if (!amount) return 1;
//        if (dp[cur][amount]) return dp[cur][amount];
//        for (int i = cur; i < coins.size(); ++i)
//            dp[cur][amount] += recur(amount - coins[i], coins, i);
//        return dp[cur][amount];
//    }
//public:
//    int change(int amount, vector<int>& coins) {
//        if (!amount) return 1;
//        if (!coins.size()) return 0;
//        int n = coins.size();
//        dp = new int*[n];
//        for (int i = 0; i < n; ++i)
//            dp[i] = new int[amount]{ 0 };
//        int result = 0;
//        for (int i = 0; i < n; ++i)
//            result += recur(amount - coins[i], coins, i);
//        return result;
//    }
//};

class Solution {
    int** dp;
public:
    int change(int amount, vector<int>& coins) {
        if (!amount) return 1;
        if (!coins.size()) return 0;
        int n = coins.size();
        dp = new int* [n];
        for (int i = 0; i < n; ++i)
        {
            dp[i] = new int[amount + 1]{ 0 };
            dp[i][0] = 1;
        }    
        for (int x = 1; x <= amount; ++x)
            for (int cur = 0; cur < n; ++cur)
                for (int i = cur; i < n; ++i)
                    if (x - coins[i] >= 0) dp[cur][x] += dp[i][x - coins[i]];
        return dp[0][amount];
    }
};
