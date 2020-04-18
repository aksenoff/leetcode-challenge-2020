// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (n == 0) return 0;
        int** minsums = new int*[n];
        int* row = new int[m];
        row[0] = grid[0][0];
        for (int j = 1; j < m; ++j)
            row[j] = row[j - 1] + grid[0][j];
        minsums[0] = row;
        for (int i = 1; i < n; ++i)
        {       
            row = new int[m];
            row[0] = minsums[i - 1][0] + grid[i][0];
            minsums[i] = row;
        }
        int left, up;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                up = minsums[i - 1][j];
                left = minsums[i][j - 1];
                minsums[i][j] = grid[i][j] + (up < left ? up : left);
            }
        }
        return minsums[n - 1][m - 1];
    }
};