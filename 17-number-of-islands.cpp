// https://leetcode.com/problems/number-of-islands/

void searchland(pair<int, int> current, set<pair<int, int>>& lands)
{
    lands.erase(current);
    auto up = make_pair(current.first + 1, current.second);
    auto down = make_pair(current.first - 1, current.second);
    auto left = make_pair(current.first, current.second - 1);
    auto right = make_pair(current.first, current.second + 1);
    if (lands.find(up) != lands.end())
        searchland(up, lands);
    if (lands.find(down) != lands.end())
        searchland(down, lands);
    if (lands.find(left) != lands.end())
        searchland(left, lands);
    if (lands.find(right) != lands.end())
        searchland(right, lands);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        const int n = grid.size();
        if (n == 0) return 0;
        const int m = grid[0].size();
        if (m == 0) return 0;
        set<pair<int, int>> lands;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == '1') lands.insert(make_pair(i, j));
        while (!lands.empty())
        {
            pair<int, int> current = *lands.begin();
            searchland(current, lands);
            result++;
        }       
        return result;
    }
};