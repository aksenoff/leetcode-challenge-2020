// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        for (auto c : S)
            if (J.find(c) != string::npos) result++;
        return result;
    }
};