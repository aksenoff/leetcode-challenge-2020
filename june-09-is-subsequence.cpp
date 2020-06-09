// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (auto sym : t)
            if (sym == s[i]) ++i;
        return i == s.size();
    }
};