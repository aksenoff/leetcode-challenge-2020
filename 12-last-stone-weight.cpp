// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int s1, s2, result;
        while (stones.size() > 1)
        {
            sort(stones.begin(), stones.end());
            s1 = stones.back();
            stones.pop_back();
            s2 = stones.back();
            stones.pop_back();
            result = abs(s1 - s2);
            if (result) stones.push_back(result);
        }
        return stones.size() ? stones.back() : 0;
    }
};