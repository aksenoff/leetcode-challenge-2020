// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int sum = 1 & x;
        for (int i = 0; i < 31; ++i) sum += (1 & (x >>= 1));
        return sum;
    }
};