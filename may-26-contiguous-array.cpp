// https://leetcode.com/problems/contiguous-array/

// Same as 13-contiguous-array.cpp, slight speed improvement

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return 0;
        int balance = 0, maxlength = 0;
        unordered_set<int> seen;
        int* balances = new int[nums.size()];
        for (size_t i = 0; i < nums.size(); i++)
        {
            balance += nums[i] ? 1 : -1;
            balances[i] = balance;
            if (!balance) maxlength = i + 1;
        }
        if (maxlength == nums.size()) return maxlength;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (seen.find(balances[i]) != seen.end()) continue;
            seen.insert(balances[i]);
            for (size_t j = nums.size() - 1; j > i; --j)
                if (balances[j] == balances[i])
                {
                    if(maxlength < j - i) maxlength = j - i;
                    break;
                }
        }
        return maxlength;
    }
};