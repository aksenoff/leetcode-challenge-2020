// https://leetcode.com/problems/longest-common-subsequence/

int lcs(string& s1, string& s2, int m, int n, int** my_map)
{
    if (!m || !n) return 0;
    if (s1[m - 1] == s2[n - 1])
    {
        if(my_map[m - 1][n - 1] == -1)
            my_map[m - 1][n - 1] = lcs(s1, s2, m - 1, n - 1, my_map);
        return 1 + my_map[m - 1][n - 1];
    }
    else
    {
        if (my_map[m - 1][n] == -1)
            my_map[m - 1][n] = lcs(s1, s2, m - 1, n, my_map);
        if (my_map[m][n - 1] == -1)
            my_map[m][n - 1] = lcs(s1, s2, m, n - 1, my_map);
        return (my_map[m - 1][n] > my_map[m][n - 1] ? my_map[m - 1][n] : my_map[m][n - 1]);
    }
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int** my_map = new int* [m + 1];
        for (int i = 0; i < m + 1; ++i)
        {
            my_map[i] = new int[n + 1];
            for (int j = 0; j < n + 1; ++j) my_map[i][j] = -1;
        }
        return lcs(text1, text2, m, n, my_map);
    }
};


// TLE:
//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        if (!text1.size() || !text2.size()) return 0;
//        if (text1.back() == text2.back())
//        {
//            text1.pop_back();
//            text2.pop_back();
//            return 1 + longestCommonSubsequence(text1, text2);
//        }
//        else
//        {
//            string t1 = text1;
//            text1.pop_back();
//            int call1 = longestCommonSubsequence(text1, text2);
//            text2.pop_back();
//            int call2 = longestCommonSubsequence(t1, text2);
//            return (call1 > call2 ? call1 : call2);
//        }
//
//    }
//};


//TLE 2:
//class Solution {
//    map<pair<int, int>, int> map1;
//public:
//    int longestCommonSubsequence(string& text1, string& text2) {
//        if (!text1.size() || !text2.size()) return 0;
//        if (text1.back() == text2.back())
//        {
//            int lcs;
//            text1.pop_back();
//            text2.pop_back();
//            auto pair = make_pair(text1.size(), text2.size());
//            if (map1.find(pair) == map1.end())
//            {
//                lcs = longestCommonSubsequence(text1, text2);
//                map1[pair] = lcs;
//            }
//            else lcs = map1[pair];
//            return 1 + lcs;
//        }
//        else
//        {
//            string t1 = text1, t2 = text2;
//            text1.pop_back();
//            int lcs1, lcs2;
//            auto pair = make_pair(text1.size(), text2.size());
//            if (map1.find(pair) == map1.end())
//            {
//                lcs1 = longestCommonSubsequence(text1, text2);
//                map1[pair] = lcs1;
//            }
//            else lcs1 = map1[pair];
//            text1 = t1;
//            text2 = t2;
//            text2.pop_back();
//            pair = make_pair(text1.size(), text2.size());
//            if (map1.find(pair) == map1.end())
//            {
//                lcs2 = longestCommonSubsequence(text1, text2);
//                map1[pair] = lcs2;
//            }
//            else lcs2 = map1[pair];
//            return (lcs1 > lcs2 ? lcs1 : lcs2);
//        }            
//    }
//};