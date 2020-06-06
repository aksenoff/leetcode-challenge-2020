// https://leetcode.com/problems/edit-distance/

class Solution {
    int** dp;
	int lev(string& s1, string& s2, int a, int b)
	{
        if (a == -1) return b + 1;
        if (b == -1) return a + 1;
        if (dp[a][b] != -1) return dp[a][b];
        dp[a][b] = min({ lev(s1, s2, a - 1, b) + 1, 
					lev(s1, s2, a, b - 1) + 1,
        			lev(s1, s2, a - 1, b - 1) + static_cast<int>(s1[a] != s2[b]) });
        return dp[a][b];
	}
public:
    int minDistance(string word1, string word2) {
        dp = new int* [word1.size()];
        for (int i = 0; i < word1.size(); ++i)
        {
            dp[i] = new int[word2.size()];
            for (int j = 0; j < word2.size(); ++j)
                dp[i][j] = -1;
        }
        return lev(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};