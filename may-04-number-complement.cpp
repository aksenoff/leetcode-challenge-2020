// https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 30;
        while (!(num & int(pow(2, i)))) --i;
        for ( ; i >= 0; --i)
            if (!(num & int(pow(2, i)))) ans |= int(pow(2, i));
        return ans;
    }
};