// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> ugly;
        ugly.reserve(n - 1);
        for (int i = 2; i <= 5; ++i) ugly.push_back(i);
        if (n < 6) return ugly[n - 2];
        int i2 = 1, i3 = 0, i5 = 0, next;
        for (int i = 0; i < n - 5; ++i)
        {
            next = min(2 * ugly[i2], min(3 * ugly[i3], 5 * ugly[i5]));
            i2 += 2 * ugly[i2] == next;
            i3 += 3 * ugly[i3] == next;
            i5 += 5 * ugly[i5] == next;
            ugly.push_back(next);
        }
        return ugly.back();
    }
};