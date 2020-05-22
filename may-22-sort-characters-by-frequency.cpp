// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        multimap<int, char> invfreq;
        string result;
        for (auto c : s)
            freq[c]++;
        for (auto f : freq)
            invfreq.insert(make_pair(f.second, f.first));
        for (auto it = invfreq.rbegin(); it != invfreq.rend(); ++it)
            for (int i = 0; i < it->first; ++i)
                result += it->second;
        return result;
    }
};