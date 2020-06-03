// https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        multimap<int, vector<int>> diffs;
        int result = 0, i = 0;
        for (auto& cost : costs)
            diffs.insert(make_pair(cost[0] - cost[1], cost));
        for (auto& diff : diffs)
            result += i++ < costs.size() / 2 ? diff.second[0] : diff.second[1];
        return result;
    }
};