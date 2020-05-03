// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        while (ransomNote.size())
        {
            int pos = magazine.find(ransomNote.back());
            if (pos == string::npos) return false;
            magazine.erase(pos, 1);
            ransomNote.pop_back();
        }
        return true;
    }
};