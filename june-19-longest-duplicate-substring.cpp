// https://leetcode.com/problems/longest-duplicate-substring/

// TLE:
// class Solution {
//     string current;
//     bool RabinKarp(const string& s1, const string& s2, int pos)
//     {
//         hash<string> hasher;
//         size_t s2h = hasher(s2);
//         int s1s = s1.size();
//         int s2s = s2.size();
//         for (int i = 0; i < s1s - s2s + 1; ++i)
//             if (hasher(s1.substr(i, s2s)) == s2h && i != pos) return true;
//         return false;
//     }
//     bool testlength(const string& S, int len)
//     {
//         int n = S.size();
//         for (int j = 0; j < n - len; ++j)
//             if (RabinKarp(S, S.substr(j, len), j))
//             {
//                 if (current.size() < len) current = S.substr(j, len);
//                 return true;
//             }
//         return false;
//     }
// public:
//     string longestDupSubstring(string S) {
//         current = "";
//         string test;
//         int n = S.size();
//         if (!n || n == 1) return "";
//         if (n == 2) return S[0] == S[1] ? string(1, S[0]) : "";
//         int a = 0, b = n - 1, mid;
//         while (a <= b)
//         {
//             mid = a + (b - a) / 2;
//             if (testlength(S, mid)) a = mid + 1;
//             else b = mid - 1;
//         }
//         return current;
//     }
// };

class Solution {
    string_view longest;
    unordered_set<string_view> set;
    bool testlength(const string& S, int len)
    {
        int n = S.size();
        for (int j = 0; j < n - len + 1; ++j)
        {
            const auto [it, inserted] = set.emplace(S.data() + j, len);
            if (!inserted)
            {
                longest = *it;
                return true;
            }
        }
        return false;
    }
public:
    string longestDupSubstring(string S) {
        int n = S.size();
        if (!n || n == 1) return "";
        if (n == 2) return S[0] == S[1] ? string(1, S[0]) : "";
        int a = 0, b = n - 1, mid;
        while (a <= b)
        {
            mid = a + (b - a) / 2;
            if (testlength(S, mid)) a = mid + 1;
            else b = mid - 1;
        }
        return {longest.begin(), longest.end()};
    }
};