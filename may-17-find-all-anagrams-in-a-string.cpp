// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_set<char> us;
        vector<int> candidates;
        vector<int> results;
        string sortedp = p; 
        sort(sortedp.begin(), sortedp.end());
        for (auto& c : p) us.insert(c);
        int len = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (us.find(s[i]) != us.end())
            {
                if (++len >= p.size()) candidates.push_back(i - p.size() + 1);
            }
            else len = 0;
        }
        string sortedpart;
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (i && candidates[i] == candidates[i - 1] + 1)
            {
                if (s[candidates[i - 1]] == s[candidates[i] + p.size() - 1])
                {
                    if (results.size() && results.back() == candidates[i - 1])
                        results.push_back(candidates[i]);
                    continue;
                }
                else
                {
                    if (results.size() && results.back() == candidates[i - 1]) continue;
                }
            }
            sortedpart = s.substr(candidates[i], p.size());
            sort(sortedpart.begin(), sortedpart.end());
            if (sortedpart == sortedp) results.push_back(candidates[i]);
        }
        return results;
    }
};