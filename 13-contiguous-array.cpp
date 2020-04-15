// https://leetcode.com/problems/contiguous-array/

#include<set>

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return 0;
        int balance = 0, maxlength = 0;
        set<int> seen;
        vector<int> balances;
        for (size_t i = 0; i < nums.size(); i++)
        {
            balance += nums[i] ? 1 : -1;
            balances.push_back(balance);
        }
        for(size_t i = balances.size() - 1; i > 0; --i)
            if (balances[i] == 0)
            {
                maxlength = i + 1;
                break;
            }
        if (maxlength == balances.size()) return maxlength;
        for (size_t i = 0; i < balances.size() - 1; i++)
        {
            if (seen.find(balances[i]) != seen.end()) continue;
            seen.insert(balances[i]);
            for (size_t j = balances.size() - 1; j > i; --j)
                if (balances[j] == balances[i])
                {
                    if(maxlength < j - i) maxlength = j - i;
                    break;
                }
        }
        return maxlength;
    }
};