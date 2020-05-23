// https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (!A.size() || !B.size()) return {};
        vector<vector<int>> result;
        int current = 0;
        for (auto p : A)
        {
            while (current < B.size() && B[current][1] < p[0]) ++current;
            while (current < B.size() && B[current][1] <= p[1])
            {
                result.push_back({ max(B[current][0], p[0]), B[current][1] });
                ++current;
            }
            if (current < B.size() && B[current][0] >= p[0] && B[current][0] <= p[1]) result.push_back({ B[current][0], p[1] });
            else if (current < B.size() && B[current][0] < p[0] && B[current][1] > p[1]) result.push_back(p);
        }
        return result;
    }
};