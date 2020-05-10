// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusts;
        trusts.resize(N + 1, 0);
        vector<int> trusted;
        trusted.resize(N + 1, 0);
        for (auto t : trust)
        {
            trusts[t[0]]++;
            trusted[t[1]]++;
        }
        int njudge = -1;
        for (int i = 1; i < N + 1; ++i)
        {
            if (trusted[i] == N - 1) 
            {
                if (njudge != -1) return -1;
                else njudge = i;
                break;
            }
        }
        if (njudge == -1) return -1;
        return (trusts[njudge] == 0 ? njudge : -1);
    }
};