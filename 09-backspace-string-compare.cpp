// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string resS = "", resT = "";
        for (auto c : S)
            if (c == '#')
            {
                if (!resS.empty()) resS.pop_back();
            }
            else resS.push_back(c);
        for (auto c : T)
            if (c == '#')
            {
                if (!resT.empty()) resT.pop_back();
            }
            else resT.push_back(c);
        return resS == resT;
    }
};