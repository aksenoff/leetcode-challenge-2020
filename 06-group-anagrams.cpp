// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> dict;
        for (auto &el : strs)
        {
            string sorted = el;
            sort(sorted.begin(), sorted.end());
            dict[sorted].push_back(el);
        }
        vector<vector<string>> result;
        for (auto& vect : dict)
        {
            result.push_back(vect.second);
        }
        return result;
    }
};