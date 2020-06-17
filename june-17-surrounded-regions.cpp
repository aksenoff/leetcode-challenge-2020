// https://leetcode.com/problems/surrounded-regions/

class Solution {
    void save(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = '1';
        if (i > 0 && board[i - 1][j] == 'O') save(board, i - 1, j);
        if (i < board.size() - 1 && board[i + 1][j] == 'O') save(board, i + 1, j);
        if (j > 0 && board[i][j - 1] == 'O') save(board, i, j - 1);
        if (j < board[0].size() - 1 && board[i][j + 1] == 'O') save(board, i, j + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (!board.size() || !board[0].size() || board.size() < 3 || board[0].size() < 3) return;
        for (int j = 0; j < board[0].size(); ++j)
            if (board[0][j] == 'O') save(board, 0, j);
        for (int i = 1; i < board.size() - 1; ++i)
            if (board[i][0] == 'O') save(board, i, 0);
        for (int j = 0; j < board[0].size(); ++j)
            if (board[board.size() - 1][j] == 'O') save(board, board.size() - 1, j);
        for (int i = 1; i < board.size() - 1; ++i)
            if (board[i][board[0].size() - 1] == 'O') save(board, i, board[0].size() - 1);
        for (auto& row : board)
            for (auto& el : row)
                if (el == '1') el = 'O';
                else if (el == 'O') el = 'X';
    }
};