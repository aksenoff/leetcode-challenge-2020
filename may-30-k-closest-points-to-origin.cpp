// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, vector<int>> proximity;
        for (auto& point : points)
        {
            auto square_length = point[0] * point[0] + point[1] * point[1];
            proximity.insert(make_pair(square_length, point));
        }
        vector<vector<int>> result;
        result.reserve(K);
        int i = 0;
        for (auto& el : proximity)
            if (i++ < K) result.push_back(el.second);
            else break;
        return result;
    }
};