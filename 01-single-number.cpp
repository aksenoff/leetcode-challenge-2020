// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for (auto num : nums)
        {
            if (!s.count(num))
                s.insert(num);
            else s.erase(num);
        }
        return *s.begin();
        
    }
};