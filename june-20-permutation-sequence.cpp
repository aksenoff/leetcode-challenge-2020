// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1 && k == 1) return "1";
        string result;
        int *fact = new int[n];
        fact[0] = 1;
        for (int i = 1; i < n; ++i)
            fact[i] = fact[i - 1] * i;
        set<int> digits;
        for (int i = 1; i <= n; ++i) digits.insert(i);
        int index, digit;
        for (int i = n; i > 0; --i)
        {
            index = (k - 1) / fact[i - 1];
            auto it = digits.begin();
            advance(it, index);
            result.push_back('0' + *it);
            digits.erase(*it);
            k = (k - 1) % fact[i - 1] + 1;
        }
        return result;
    }
};