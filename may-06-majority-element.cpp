// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int, int> freq;
        for (auto& el : nums)
            if (freq.find(el) == freq.end()) freq[el] = 1;
            else freq[el]++;
        for (auto& fr : freq)
            if (fr.second > n) return fr.first;
        return -1;
    }
};