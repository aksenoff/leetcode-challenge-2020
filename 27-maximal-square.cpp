// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int** dp = new int*[m + 1];
        int** mat = new int*[m + 1];
        int* first_row_dp = new int[n + 1];
        int* first_row_mat = new int[n + 1];
        for (int j = 0; j < n + 1; ++j) first_row_dp[j] = first_row_mat[j] = 0;
        dp[0] = first_row_dp;
        mat[0] = first_row_mat;
        for (int i = 1; i < m + 1; ++i)
        {
            int* row_dp = new int[n + 1];
            int* row_mat = new int[n + 1];
            row_dp[0] = row_mat[0] = 0;
            for (int j = 1; j < n + 1; ++j) row_mat[j] = matrix[i - 1][j - 1] - '0';
            dp[i] = row_dp;
            mat[i] = row_mat;
        }
        int max = 0;
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (mat[i][j])
                {
                    if (mat[i - 1][j - 1])
                    {
                        bool flag_up = true, flag_left = true;
                        int up = 0, left = 0;
                        for (int x = 1; x <= dp[i - 1][j - 1]; ++x)
                            if (!mat[i - x][j])
                            {
                                flag_up = false;
                                break;
                            }
                            else up++;
                        if (up)
                            for (int x = 1; x <= dp[i - 1][j - 1]; ++x)
                                if (!mat[i][j - x])
                                {
                                    flag_left = false;
                                    break;
                                }
                                else left++;
                        if (flag_up && flag_left) dp[i][j] = dp[i - 1][j - 1] + 1;
                        else dp[i][j] = 1 + (up < left ? up : left);
                    }
                    else dp[i][j] = 1;
                    if (dp[i][j] > max) max = dp[i][j];
                }
            }
        }
        return max * max;
    }
};