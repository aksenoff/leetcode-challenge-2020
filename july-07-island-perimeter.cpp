// https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;
        int result = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!grid[i][j]) continue;
                if (i > 0) result += !grid[i - 1][j]; else ++result;
                if (j > 0) result += !grid[i][j - 1]; else ++result;
                if (i < m - 1) result += !grid[i + 1][j]; else ++result;
                if (j < n - 1) result += !grid[i][j + 1]; else ++result;
            }
        }
        return result;
    }
};