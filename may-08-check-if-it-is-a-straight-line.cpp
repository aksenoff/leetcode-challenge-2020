// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        vector<int> p1 = coordinates.back();
        coordinates.pop_back();
        vector<int> p2 = coordinates.back();
        coordinates.pop_back();
        bool h = p2[1] == p1[1];
        bool v = p2[0] == p1[0];
        for (auto p : coordinates)
        {
            if (h)
            {
                if (p[1] != p1[1])
                    return false;
            }
            else if (v)
            {
                if (p[0] != p1[0])
                    return false;
            }
            else if ((p[0] - p1[0]) / (p2[0] - p1[0]) != (p[1] - p1[1]) / (p2[1] - p1[1]))
                return false;
        }
        return true;
    }
};