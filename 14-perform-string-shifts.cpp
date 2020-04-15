// https://leetcode.com/problems/perform-string-shifts/

#include<algorithm>

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if (shift.size() == 0) return s;
        int finalshift = 0;
        for (auto sh : shift) finalshift += sh[1] * (sh[0] ? 1 : -1);
        finalshift %= (int)s.size();
        if (finalshift < 0) finalshift += s.size();
        reverse(s.begin(), s.end() - finalshift);
        reverse(s.end() - finalshift, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};