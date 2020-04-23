// https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        bitset<32> bits_m(m), bits_n(n);
        string str_m = bits_m.to_string(), str_n = bits_n.to_string(), str_result;
        int i = 0;
        while (str_m[i] == str_n[i] && i < 32) str_result.push_back(str_n[i++]);
        while (i++ < 32) str_result.push_back('0');
        bitset<32> result(str_result);
        return result.to_ulong();
    }
};