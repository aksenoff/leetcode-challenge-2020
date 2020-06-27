// https://leetcode.com/problems/perfect-squares/

class Solution {
    vector<int> squares;
    int* dp;
    int recur(int x)
    {
        if (x < 0) return 30000;
        if (x == 0) return 0;
        if (dp[x]) return dp[x];
        int best = 30000;
        for (auto square : squares) best = min(best, recur(x - square) + 1);
        dp[x] = best;
        return best;
    }
public:
    int numSquares(int n) {
        int root = static_cast<int>(sqrt(n));
        squares.reserve(root);
        dp = new int[n + 1]{0};
        for (int i = 1; i <= root; ++i) squares.push_back(i * i);
        return recur(n);
    }
};