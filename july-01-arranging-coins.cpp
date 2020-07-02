// https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        return floor((1 + sqrt(1 + 4L * 2 * n)) / 2.) - 1;
    }
};