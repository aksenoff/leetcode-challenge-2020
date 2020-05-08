// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set<char> seen;
        for (int i = 0; i < s.size(); ++i)
        {
            if (seen.find(s[i]) != seen.end()) continue;
            if (s.find(s[i], i + 1) != string::npos) seen.insert(s[i]);
            else return i;
        }
        return -1;
    }
};