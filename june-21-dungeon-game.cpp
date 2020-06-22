// https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(std::vector<vector<int>>& dungeon) {
        int m = dungeon.size() ;
        int n = dungeon[0].size();
        int** dp = new int* [m + 1];
        for (int i = 0; i <= m; ++i)
            dp[i] = new int[n + 1];
        for (int i = 0; i <= m; ++i)
            dp[i][n] = 40000;
        for (int i = 0; i <= n; ++i)
            dp[m][i] = 40000;
        dp[m - 1][n - 1] = 1 - min(dungeon[m - 1][n - 1], 0);
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i == m - 1 && j == n - 1) continue;
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (dp[i][j] <= 0) dp[i][j] = 1;
            }
        }
        return dp[0][0];
    }
};