// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        set<char> symbols;
        int freq[26] = {}, s1freq[26] = {};
        for (auto& c : s1)
        {
            symbols.insert(c);
            s1freq[c - 'a']++;
        }
        int len = 0;
        for (int i = 0; i < s2.size(); ++i)
        {
            if (symbols.find(s2[i]) != symbols.end())
            {
                freq[s2[i] - 'a']++;
                if (++len > s1.size()) freq[s2[i - s1.size()] - 'a']--;
                if (len >= s1.size())
                {
                    bool win = true;
                    for (auto sym : symbols)
                    {                        
                        if (freq[sym - 'a'] != s1freq[sym - 'a'])
                        {
                            win = false;
                            break;
                        }                        
                    }
                    if (win) return true;
                }
            }
            else
            {
                len = 0;
                for (auto sym : symbols) freq[sym - 'a'] = 0;
            }
        }
        return false;
    }
};
