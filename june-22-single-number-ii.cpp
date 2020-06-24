// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> seen, dup;
        for (auto el : nums)
        {
            if (seen.find(el) == seen.end())
            {
                if (dup.find(el) == dup.end()) seen.insert(el);
                else continue;
            }
            else
            {
                seen.erase(el);
                dup.insert(el);
            }
        }
        return *seen.begin();
    }
};