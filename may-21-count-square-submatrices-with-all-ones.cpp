https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 || n == 1)
        {
            int sum = 0;
            for (auto row : matrix)
                for (auto el : row)
                    sum += el;
            return sum;
        }
        int** dp = new int* [m];
        for (int i = 0; i < m; ++i)
        {
            int* row_dp = new int[n];
            for (int j = 0; j < n; ++j)
            {
                row_dp[j] = matrix[i][j];
                if (i) row_dp[j] += dp[i - 1][j];
                if (j) row_dp[j] += row_dp[j - 1];
                if (i && j) row_dp[j] -= dp[i - 1][j - 1];
            }
            dp[i] = row_dp;
        }
        int max_size = m < n ? m : n;
        int result = 0;
        for (int size = max_size; size >= 1; --size)
        {
            for (int x = size - 1; x < m; ++x)
            {
                for (int y = size - 1; y < n; ++y)
                {
                    int sum = dp[x][y];
                    if (x - size + 1) sum -= dp[x - size][y];
                    if (y - size + 1) sum -= dp[x][y - size];
                    if ((x - size + 1) && (y - size + 1)) sum += dp[x - size][y - size];
                    if (sum == size * size) result++;
                }
            }
        }
        return result;
    }
};