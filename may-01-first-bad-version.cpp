// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int a = 1, b = n;
        if (isBadVersion(a)) return a;
        while (a < b - 1)
        {
            int mid = a + (b - a) / 2;
            isBadVersion(mid) ? b = mid : a = mid;            
        }
        return b;
    }
};